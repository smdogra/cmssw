///
/// Description: Firmware headers
///
/// Implementation:
/// Collects concrete algorithm implmentations.
///
/// \author: R. Alex Barbieri MIT
///

//
// This header file contains the class definitions for all of the concrete
// implementations of the firmware interface. The Stage1Layer2FirmwareFactory
// selects the appropriate implementation based on the firmware version in the
// configuration.
//

#ifndef L1TCALOSTAGE1EGAMMAALGORITHMIMP_H
#define L1TCALOSTAGE1EGAMMAALGORITHMIMP_H

#include "L1Trigger/L1TCalorimeter/interface/Stage1Layer2EGammaAlgorithm.h"
//#include "CondFormats/L1TCalorimeter/interface/CaloParams.h"

namespace l1t {

  class Stage1Layer2EGammaAlgorithmImpPP : public Stage1Layer2EGammaAlgorithm {
  public:
    Stage1Layer2EGammaAlgorithmImpPP(/*const CaloParams & dbPars*/);
    virtual ~Stage1Layer2EGammaAlgorithmImpPP();
    virtual void processEvent(const std::vector<l1t::CaloEmCand> & clusters,
			      const std::vector<l1t::CaloRegion> & regions,
			      std::vector<l1t::EGamma> & egammas,
			      std::list<L1GObject> & rlxEGList,
			      std::list<L1GObject> & isoEGList);

    unsigned int egtSeed;

    double puLevel;
    double relativeIsolationCut;
    double relativeJetIsolationCut;

  };
}

#endif
