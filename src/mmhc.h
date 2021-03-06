#ifndef CLASSES_H
#define CLASSES_H

// include libraries and set namespaces
#include <Rcpp.h>
#include <cstdlib>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;
using namespace Rcpp;

// define the prototype of the class
class MMHC {
    private: // private variables
		int vDim, hDim, maxi;
		double alpha, eta, score;
		List pc;
		IntegerMatrix A, graph;
		IntegerVector cardinality;
		NumericVector scores;
        double* D1;
        double* D11;
        double** D2;
        double** D22;
        double*** D3;
        double*** D33;
        double**** D4;
        double**** D44;
        double***** D5;
	public: // public variables and methods
        MMHC(); // default constructor (needed!!!)
		MMHC(SEXP); // my constructor
		~MMHC();

		SEXP GetPC() {return this->pc;}
		double GetScore() {return this->score;}
		SEXP GetGraph() {return this->graph;}
        SEXP GetMat() {return this->A;}

		template <typename T, int RTYPE> int colCardinality(const Vector<RTYPE>& x, unordered_map<T, int>& y);
		void Cardinality();
		int Hash(IntegerVector&, int, bool);
		double* OneD(double);
		double** TwoD(double, double);
		double*** ThreeD(double, double, double);
		double**** FourD(double, double, double, double);
		double***** FiveD(double, double, double, double, double);
		NumericVector Svalue(IntegerMatrix&, const IntegerVector&);
		IntegerMatrix partialMatrix(const IntegerVector&);
		IntegerVector CorrespondingCardinality(const IntegerVector&);
		IntegerVector SetCols(const IntegerVector&, int, int);
		void UpdateCPC(List&, double);
		bool IsIn(const IntegerVector&, double);
		void MaxMinHeuristic(const IntegerVector&, List&, IntegerVector&, int);
		void CompatibilityToR(IntegerVector&);
		List Forward(int);
		IntegerVector Backward(List&, int);

		unordered_map<int, int> UniqueMap(IntegerMatrix&);
		int getSingleN_ijk(IntegerVector&, int);
		int getVecN_ijk(IntegerVector&, IntegerVector&, int, int);
		int getMapN_ijk(IntegerVector&, IntegerMatrix&, unordered_map<int, int>, int, int);
		double ScoreNodeWithNoneParents(IntegerVector&, int);
		double ScoreNodeWithOneParent(IntegerVector&, IntegerVector&, int, int);
		double ScoreNodeWithMoreParents(IntegerVector&, IntegerMatrix&, int, int);
		NumericVector ReturnParents(int, IntegerMatrix&);
		void InitScore();
		void ScoreGraph(IntegerMatrix&, NumericVector&);
		void SettingEdges();
		void AddReverseDelete(IntegerMatrix&, NumericVector&);

		void mmpc();
		void mmhc();
};

#endif