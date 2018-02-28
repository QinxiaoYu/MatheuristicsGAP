﻿#ifndef GAP_H
#define GAP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>    /* srand, rand */
#include <time.h>     /* time */
#include <assert.h>   /* assert */

using namespace std;

class Config
{
   public:
      class SimAnn
      {  public:
            double maxT;
            double k;
            double alpha;
            int iterAnneal;
            int maxiter;
            friend class Config;
      };

      class Tabu
      {  public:
         int Ttenure;
         int maxiter;
      };

      class IteratedLS
      {  public:
         int maxiter;
         double alpha;
      };

      class GeneticConf
      {  public:
         int maxiter;
         int numpop; // num individuals in population
         double pc;  // crossover probability
      };

      class EjectionConf
      {  public:
         int maxiter;
      };

      class LagrAss
      {
         public:
            double alpha;
            double alphastep;
            double minalpha;
            int maxiter;
            int innerIter;
      };

      class RinsConf
      {  public:
            int maxnodes;
      };

      class Beam
      {  public:
         int delta;
         int maxnodes;
      };

      class FBconf
      {  public:
         int delta;
         int maxnodes;
      };

      class LagrCap
      {
         public:
            double alpha;
            double alphastep;
            double minalpha;
            int maxiter;
            int innerIter;
      };

      class CorridorConf
      {  public:
            int delta;
            int maxiter;
      };

      class LocBranching
      {  public:
            int k;
            int maxiter;
      };

      class BendersConf
      {  public:
            int maxiter;
      };

      // -------------------- reminder: initialize these in the Config constructor!
      SimAnn*       SA;
      Tabu*         TS;
      GeneticConf*  GA;
      EjectionConf* EC;
      IteratedLS*   IterLS;
      LagrAss*      lagrAss;
      LagrCap*      lagrCap;
      LocBranching* locBranching;
      RinsConf*     rinsConf;
      Beam*         beam;
      FBconf*       fbConf;
      CorridorConf* corridorConf;
      BendersConf*  bendersConf;
      string  datafile;
      int     isVerbose;

      Config();
};

class GeneralizedAssignemnt
{
   public:
      GeneralizedAssignemnt();
      ~GeneralizedAssignemnt();
      string name; // instance name
      int n;       // number of clients
      int m;       // number of servers
      int nDays;   // planning horizon (if scheduling)
      int** c;     // assignment costs
      int** req;   // client requests
      int*  cap;   // server capacities

      Config* conf;

      int *sol,*solbest;    // for each client, its server
      int zub,zlb;

      double EPS;

      int checkSol(int* sol);                       // feasibility check
      int fixSol(int* infeasSol, int* zsol);        // recovers feasibility in case of partial or overassigned solution
      int fixSolViaKnap(int* infeasSol, int* zsol); // recovers feasibility via knapsacks on residual capacities
};

// free
void computeRegrets(int**, int, int, vector<int> & );
double KDynRecur(int n, int Kcap, int* Q, double* val, int* Ksol);
void KdecodeSol(int i, int Kcap, int* Q, double* val, int n, double** f, int* sol);
void printDblArray(double* a, int n);

#endif // GAP_H