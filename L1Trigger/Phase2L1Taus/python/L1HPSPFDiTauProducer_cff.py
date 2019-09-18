import FWCore.ParameterSet.Config as cms

L1HPSPFDiTauProducer = cms.EDProducer("L1HPSPFDiTauProducer",
  srcL1HPSPFTaus            = cms.InputTag("L1HPSPFTauProducerWithStripsWithoutPreselectionPF"),
  deltaZ                    = cms.double(0.4),
  debug                     = cms.untracked.bool(False)                                  
)
