#ifndef DataFormats_Phase2L1Taus_L1HPSPFDiTau_H
#define DataFormats_Phase2L1Taus_L1HPSPFDiTau_H

#include "DataFormats/Phase2L1Taus/interface/L1HPSPFTau.h" //l1t::L1HPSPFTau

// forward declation needed in order to declare L1HPSPFDiTauProducer class as friend (that has access to private data-members) 
class L1HPSPFDiTauProducer;

namespace l1t
{

class L1HPSPFDiTau : public l1t::L1HPSPFTau
{
 public:
  /// default constructor
  L1HPSPFDiTau();
    
  /// destructor
  ~L1HPSPFDiTau();

  const l1t::L1HPSPFTau& leadingL1HPSPFTau()  const { return leadingL1HPSPFTau_; }
  const l1t::L1HPSPFTau& subleadingL1HPSPFTau() const { return subleadingL1HPSPFTau_; }

  float dzBetweenDiTau()                       const { return dzBetweenDiTau_; }

  friend class ::L1HPSPFDiTauProducer;

 private:
  l1t::L1HPSPFTau leadingL1HPSPFTau_;
  l1t::L1HPSPFTau subleadingL1HPSPFTau_;

  float dzBetweenDiTau_;

};

}

#endif 
