#include "L1Trigger/Phase2L1Taus/interface/L1HPSPFDiTauProducer.h"

#include "FWCore/Utilities/interface/InputTag.h"

#include <cmath> // std::fabs

L1HPSPFDiTauProducer::L1HPSPFDiTauProducer(const edm::ParameterSet& cfg) 
  : deltaZ_(cfg.getParameter<double>("deltaZ"))
  , debug_(cfg.getUntrackedParameter<bool>("debug", false))
{

  srcL1HPSPFTaus_   = cfg.getParameter<edm::InputTag>("srcL1HPSPFTaus");
  tokenL1HPSPFTaus_ = consumes<l1t::L1HPSPFTauCollection>(srcL1HPSPFTaus_);

  produces<l1t::L1HPSPFDiTauCollection>();
}

L1HPSPFDiTauProducer::~L1HPSPFDiTauProducer()
{}


void L1HPSPFDiTauProducer::produce(edm::Event& evt, const edm::EventSetup& es)
{
  std::unique_ptr<l1t::L1HPSPFDiTauCollection> l1HPSPFDiTauCollection(new l1t::L1HPSPFDiTauCollection());

  edm::Handle<l1t::L1HPSPFTauCollection>  l1HPSPFTaus;
  evt.getByToken(tokenL1HPSPFTaus_,     l1HPSPFTaus);

  if ( debug_ )
    {
      int nTaus = l1HPSPFTaus->size();
      std::cout << " Number of Taus " << nTaus << std::endl;
    }

  for( l1t::L1HPSPFTauCollection::const_iterator Tau1 = l1HPSPFTaus->begin(); Tau1 != l1HPSPFTaus->end(); Tau1++ )
    {
      if ( debug_ )
	{
	  std::cout << " In First Loop " << std::endl;
	}

      double z1 = 1000;
      if ( Tau1->leadChargedPFCand().isNonnull() && Tau1->leadChargedPFCand()->pfTrack().isNonnull())
	{
	  z1 = Tau1->leadChargedPFCand()->pfTrack()->vertex().z();
	}

      bool isDiTau = false;
      for( l1t::L1HPSPFTauCollection::const_iterator Tau2 = Tau1+1; Tau2 != l1HPSPFTaus->end(); Tau2++ )
	{
	  if ( debug_ )
	    {
	      std::cout << " In Second Loop " << std::endl;
	    }

	  double z2 = 2000;
	  if ( Tau2->leadChargedPFCand().isNonnull() && Tau2->leadChargedPFCand()->pfTrack().isNonnull())
	    {
	      z2 = Tau2->leadChargedPFCand()->pfTrack()->vertex().z();
	    }

	  double dz_ = z1 - z2;

	  if ( std::fabs(dz_) < deltaZ_ )
	    {
	      l1t::L1HPSPFDiTau l1HPSPFDiTau_;
	      l1HPSPFDiTau_.dzBetweenDiTau_ = dz_;
	      l1HPSPFDiTau_.leadingL1HPSPFTau_ = *Tau1;
              l1HPSPFDiTau_.subleadingL1HPSPFTau_= *Tau2;
	      l1HPSPFDiTauCollection->push_back(l1HPSPFDiTau_);
	      isDiTau = true;
	      break; // comment to save all possible pair in a event
	    }
	}
      if ( isDiTau )
	{
	  break; // comment to save all possible pair in a event
	}
    }
  
  evt.put(std::move(l1HPSPFDiTauCollection));
  
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(L1HPSPFDiTauProducer);
