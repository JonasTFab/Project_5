#include <iostream>
#include <armadillo>
//#include "mpi.h"

//For debugging:
// compile with: g++ main.cpp -o main1 -larmadillo -llapack -lblas
// execute with ./main1 length temperature ordered/random

//For paralellization
//mpicxx  -o main_mpi.x  main.cpp -std=c++11
//mpiexec -n 2 ./main_mpi.x
