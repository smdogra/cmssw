#ifndef CentralitypADQM_H
#define CentralitypADQM_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "DQMServices/Core/interface/DQMEDAnalyzer.h"

#include "DataFormats/HeavyIonEvent/interface/EvtPlane.h"
#include "RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
class DQMStore;

class CentralitypADQM : public DQMEDAnalyzer {

 public:
  explicit CentralitypADQM(const edm::ParameterSet& ps);
  virtual ~CentralitypADQM();

 protected:
  virtual void analyze(edm::Event const& e, edm::EventSetup const& eSetup) override;

 private:
  virtual void bookHistograms(DQMStore::IBooker& bei, edm::Run const&,
                              edm::EventSetup const&) override;

  // void bookHistos(DQMStore * bei );
  //  DQMStore* bei_;

  //  edm::InputTag centrality_; //CMSS_5_3x
  //  edm::InputTag vertex_;  //CMSS_5_3x

  edm::InputTag centralityTag_;
  edm::EDGetTokenT<reco::Centrality> centralityToken;
  edm::Handle<reco::Centrality> centrality_;

  edm::InputTag vertexTag_;
  edm::EDGetTokenT<std::vector<reco::Vertex> > vertexToken;
  edm::Handle<std::vector<reco::Vertex> > vertex_;

  edm::InputTag  eventplaneTag_;
  edm::EDGetTokenT<reco::EvtPlaneCollection> eventplaneToken;
  
  edm::InputTag centralityBinTag_;
  edm::EDGetTokenT<int> centralityBinToken;
  edm::Handle<int>centralityBin_;


  ///////////////////////////
  // Histograms
  ///////////////////////////

  // Histograms - Centrality
  MonitorElement* h_hiNpix;
  MonitorElement* h_hiNpixelTracks;
  MonitorElement* h_hiNtracks;
  MonitorElement* h_hiNtracksPtCut;
  MonitorElement* h_hiNtracksEtaCut;
  MonitorElement* h_hiNtracksEtaPtCut;
  MonitorElement* h_hiHF;
  MonitorElement* h_hiHFplus;
  MonitorElement* h_hiHFminus;
  MonitorElement* h_hiHFplusEta4;
  MonitorElement* h_hiHFminusEta4;
  MonitorElement* h_hiHFhit;
  MonitorElement* h_hiHFhitPlus;
  MonitorElement* h_hiHFhitMinus;
  MonitorElement* h_hiEB;
  MonitorElement* h_hiET;
  MonitorElement* h_hiEE;
  MonitorElement* h_hiEEplus;
  MonitorElement* h_hiEEminus;
  MonitorElement* h_hiZDC;
  MonitorElement* h_hiZDCplus;
  MonitorElement* h_hiZDCminus;

  MonitorElement* h_vertex_x;
  MonitorElement* h_vertex_y;
  MonitorElement* h_vertex_z;

  MonitorElement* h_cent_bin;

  MonitorElement* h_ep_HFm1;
  MonitorElement* h_ep_HFp1;
  MonitorElement* h_ep_trackm1;
  MonitorElement* h_ep_trackp1;
  MonitorElement* h_ep_castor1;

  MonitorElement* h_ep_HFm2;
  MonitorElement* h_ep_HFp2;
  MonitorElement* h_ep_trackmid2;
  MonitorElement* h_ep_trackm2;
  MonitorElement* h_ep_trackp2;
  MonitorElement* h_ep_castor2;

  MonitorElement* h_ep_HFm3;
  MonitorElement* h_ep_HFp3;
  MonitorElement* h_ep_trackmid3;

};

#endif
