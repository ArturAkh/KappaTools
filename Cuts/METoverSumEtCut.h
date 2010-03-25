#ifndef KMEToverSumEtCut_h
#define KMEToverSumEtCut_h

#include "BaseCut.h"
#include "DataFormats/interface/KBasic.h"

namespace KappaTools
{
	template <typename METType>
	class METoverSumEtCut : public BaseCut
	{
		private:
			METType * obj;
			double min;
			double max;
		public:
			METoverSumEtCut() : BaseCut("MET/Et cut"), obj(0), min(0.), max(1.) {};
			METoverSumEtCut(METType * tmpObj) : BaseCut("MET/Et cut"), obj(tmpObj), min(0.), max(1.) {};
		
			void setPointer(METType * tmpObj);
			
			void setMinCut(double min_);
			void setMaxCut(double max_);
		
			virtual bool getInternalDecision();
			double getDecisionValue();
	};

	template <typename METType>
	void METoverSumEtCut<METType>::setPointer(METType * tmpObj)
	{
		obj=tmpObj;
	}

	template <typename METType>
	void METoverSumEtCut<METType>::setMinCut(double min_)
	{
		min=min_;
	}

	template <typename METType>
	void METoverSumEtCut<METType>::setMaxCut(double max_)
	{
		max=max_;
	}

	template <typename METType>
	bool METoverSumEtCut<METType>::getInternalDecision()
	{
		if (!obj)
			return false;
	
		double val = getDecisionValue();
	
		return (val>min && val<max);
	};

	template <typename METType>
	double METoverSumEtCut<METType>::getDecisionValue()
	{
		if (!obj)
			return -1.;

		return obj->p4.Et()/obj->sumEt;
	};
}
#endif