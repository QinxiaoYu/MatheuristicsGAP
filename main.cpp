#include <iostream>
#include "Controller.h"

int main()
{  int input;
   clock_t start, end;
   Controller* C = new Controller();

   do{
      cout << "\n\nMatHeuristics, select:" << endl;
      cout << "1) Lower bounds" << endl;
      cout << "2) Exact" << endl;
      cout << " ----------------------------------- 1: simple heuristics" << endl;
      cout << " 3) Simple constructive" << endl;
      cout << " 4) MTHG" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : " 5") << ") opt01" << endl;
      cout << " ----------------------------------- 2: metaheuristics" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : " 6") << ") Simulated Annealing" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : " 7") << ") Tabu Search" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : " 8") << ") Iterated Local Search (with data perturbation)" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : " 9") << ") GRASP" << endl;
      cout << (C->GAP->zub == INT_MAX ? " X" : "10") << ") VNS" << endl;
      cout << "11) Ejection chains" << endl;
      cout << "12) Genetic algorithm" << endl;
      cout << "13) Ant Colony Optimization" << endl;
      cout << " ----------------------------------- 3: MH uniques" << endl;
      cout << "14) Lagrangian, relax capacities" << endl;
      cout << "15) Lagrangian, relax assignments" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "16") << ") Rins" << endl;
      cout << "17) Beam search" << endl;
      cout << "18) Forward & Backward" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "19") << ") Corridor" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "20") << ") Local Branching" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "21") << ") Benders" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "22") << ") Kernel search" << endl;
      cout << (C->GAP->zub == INT_MAX ? "X" : "23") << ") Very large-scale neigh search" << endl;
      cout << endl;
      cout << "0) Exit" << endl;
      cout << "\n->";

      cin >> input;
      start = clock();
      switch (input) 
      {
      case (1): 
         cout << "Lower bounds" << endl;
         C->computeBounds();
         break;
      case (2): 
         cout << "Exact (cplex)" << endl;
         C->exactCplex();
         break;
      case (3): 
         cout << "Simple constructive" << endl;
         C->simpleContruct();
         break;
      case (4): 
         cout << "MTHG" << endl;
         C->run_mthg();
         break;
      case (5): 
         cout << "opt01" << endl;
         C->opt10();
         break;
      case (6): 
         cout << "Simulated Annealing" << endl;
         C->run_simAnn();
         break;
      case (7): 
         cout << "Tabu Search" << endl;
         C->run_tabuSearch();
         break;
      case (8):
         cout << "Iterated Local Search" << endl;
         C->run_iteratedLS();
         break;
      case (9):
         cout << "GRASP" << endl;
         C->run_GRASP();
         break;
      case (10):
         cout << "VNS" << endl;
         C->run_VNS();
         break;
      case (11):
         cout << "Ejection chain" << endl;
         C->run_ejection();
         break;
      case (12):
         cout << "Genetic algorithm" << endl;
         C->run_genAlgo();
         break;
      case (13):
         cout << "Ant Colony Optiization" << endl;
         C->run_ACO();
         break;
      case (14):
         cout << "Lagrangian, relax assignments" << endl;
         C->run_lagrAss();
         break;
      case (15): 
         cout << "Lagrangian, relax capacities" << endl;
         C->run_lagrCap();
         break;
      case (16): 
         cout << "Rins" << endl;
         C->run_rins();
         break;
      case (17): 
         cout << "Beam search" << endl;
         C->run_beam();
         break;
      case (18): 
         cout << "Forward & Backward" << endl;
         C->run_FandB();
         break;
      case (19): 
         cout << "Corridor" << endl;
         C->run_Corridor();
         break;
      case (20): 
         cout << "Local branching" << endl;
         C->run_localBranching();
         break;
      case (21):
         cout << "Benders" << endl;
         C->run_benders();
         break;
      case (22):
         cout << "Kernel" << endl;
         C->run_kernel();
         break;
      case (23):
         cout << "VLSN" << endl;
         C->run_VLSN();
         break;
      case (0):
         goto lend;
         break;
      default:
         cout << "Error in input choice" << endl;
         input = 666;
         break;
      }
      end = clock();
      cout << "Time: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
   } while(true);

lend:  
   delete C;
   cout << "\n<ENTER> to exit ..."; cin.get();
   return 0;
}
