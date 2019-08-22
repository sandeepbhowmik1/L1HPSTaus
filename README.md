# L1HPSTaus
Developing HPS Tau algorithm for CMS L1 trigger for Phase2

# ------------- Install CMSSW ---------------------

cmsrel CMSSW_10_6_1_patch2

cd CMSSW_10_6_1_patch2/src

cmsenv

git cms-init

#git remote add cms-l1t-offline git@github.com:cms-l1t-offline/cmssw.git

git remote add cms-l1t-offline https://github.com/sandeepbhowmik1/cmssw

git fetch cms-l1t-offline phase2-l1t-integration-CMSSW_10_6_1_patch2

git cms-merge-topic -u cms-l1t-offline:l1t-phase2-v2.22.1-CMSSW_10_6_1_patch2

git cms-addpkg L1Trigger/L1TCommon

scram b -j 8

git clone https://github.com/sandeepbhowmik1/L1HPSTaus fileToCopy



# ----------- place DataFormats -------------------

cp -r fileToCopy/DataFormats/Phase2L1Taus $CMSSW_BASE/src/DataFormats/

cp fileToCopy/DataFormats/Phase2L1ParticleFlow/interface/PFCandidate.h $CMSSW_BASE/src/DataFormats/Phase2L1ParticleFlow/interface/

cp fileToCopy/DataFormats/Phase2L1ParticleFlow/src/classes.h $CMSSW_BASE/src/DataFormats/Phase2L1ParticleFlow/src/

cp fileToCopy/DataFormats/Phase2L1ParticleFlow/src/classes_def.xml $CMSSW_BASE/src/DataFormats/Phase2L1ParticleFlow/src/

cp fileToCopy/DataFormats/L1TVertex/interface/Vertex.h $CMSSW_BASE/src/DataFormats/L1TVertex/interface/

cp fileToCopy/DataFormats/L1TVertex/src/classes.h  $CMSSW_BASE/src/DataFormats/L1TVertex/src/

cp fileToCopy/DataFormats/L1TVertex/src/classes_def.xml $CMSSW_BASE/src/DataFormats/L1TVertex/src/


# ------------ place L1Trigger --------------------

cp fileToCopy/L1Trigger/Phase2L1Taus/BuildFile.xml $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/

cp fileToCopy/L1Trigger/Phase2L1Taus/interface/L1HPSPFTauProducer.h $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/interface/

cp fileToCopy/L1Trigger/Phase2L1Taus/interface/L1HPSPFTauBuilder.h $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/interface/

cp fileToCopy/L1Trigger/Phase2L1Taus/interface/LocalFileInPath.h $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/interface/

cp fileToCopy/L1Trigger/Phase2L1Taus/interface/lutAuxFunctions.h $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/interface/

cp fileToCopy/L1Trigger/Phase2L1Taus/interface/L1HPSPFTauQualityCut.h $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/interface/


cp fileToCopy/L1Trigger/Phase2L1Taus/src/L1HPSPFTauBuilder.cc $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/src/

cp fileToCopy/L1Trigger/Phase2L1Taus/src/LocalFileInPath.cc $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/src/

cp fileToCopy/L1Trigger/Phase2L1Taus/src/lutAuxFunctions.cc $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/src/

cp fileToCopy/L1Trigger/Phase2L1Taus/src/L1HPSPFTauQualityCut.cc $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/src/


cp fileToCopy/L1Trigger/Phase2L1Taus/plugins/BuildFile.xml $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/plugins/

cp fileToCopy/L1Trigger/Phase2L1Taus/plugins/L1HPSPFTauProducer.cc $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/plugins/


cp fileToCopy/L1Trigger/Phase2L1Taus/python/L1HPSPFTauProducerPuppi_cff.py $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/python/

cp fileToCopy/L1Trigger/Phase2L1Taus/python/L1HPSPFTauProducerPF_cff.py $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/python/


cp fileToCopy/L1Trigger/Phase2L1Taus/test/produceL1HPSPFTaus_cfg.py $CMSSW_BASE/src/L1Trigger/Phase2L1Taus/test/


rm -rf fileToCopy


scram b -j 8

