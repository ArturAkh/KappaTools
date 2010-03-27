#ifndef KMuonPlots_h
#define KMuonPlots_h

#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TDirectory.h"
#include "BasePlot.h"
#include "DataFormats/interface/KMuon.h"
/*
#include "TFile.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TString.h"
#include <Math/VectorUtil.h>

//#include <Math/LorentzVector.h>
//#include <Math/PtEtaPhiM4D.h>
#include "../../MTAObjects/interface/MTAMuon.h"
#include "../../MTAObjects/interface/MTAVertex.h"
#include "../../MTAObjects/interface/MTAGenParticle.h"
#include <cmath>
#include <stdlib.h>
*/

namespace KappaTools
{
	class StandardMuonPlots : public BasePlot
	{
		private:
			TH1D * muon_pt, * muon_pt_low;
			TH1D * muon_eta, * muon_eta_zoom, * muon_phi;

			TH1D * muon_hasVertex;

			TH1D * muon_ecalIso03;
			TH1D * muon_hcalIso03;
			TH1D * muon_trackIso03;

			TH1D * muon_ecalIso06;
			TH1D * muon_hcalIso06;
			TH1D * muon_trackIso06;

			TH1D * muon_trackHits;
			TH1D * muon_numberOfChambers;

			TH1D * vertex_chi2;
			TH1D * vertex_ndof;
			TH1D * vertex_chi2norm;
			TH1D * vertex_chi2prob;

			TH1D * IP;
			TH1D * IPSig;
			TH2D * IPvsIPSig;

			TH1D * muon_type;

			TH1D * track_chi2;
			TH1D * track_ndof;
			TH1D * track_chi2norm;
			TH1D * track_chi2prob;
			/*
				MTAPoint vertex;
				double vertex_chi2;
				double vertex_ndof;
				double vertex_chi2prob;

				-- bool isTrackerMuon;
				-- bool isCaloMuon;
				-- bool isStandAloneMuon;
				-- bool isGlobalMuon;

				-- float hcalIso03;
				-- float ecalIso03;
				-- float trackIso03;

				unsigned int isGoodMuon;

				float caloComp, segComp;

				-- int numberOfChambers;
				-- int trackHits;
			*/
		public:
			StandardMuonPlots(TDirectory * tmpFile, TString tmpDirectory, TString tmpSubDirectory="");

			// TDirectory
			void process(KDataMuon * muon, KDataVertex * pv = 0, double weight = 1.);
			void final();
	};
}
#endif
