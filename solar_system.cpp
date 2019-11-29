#include <iostream>
#include <fstream>
#include <iomanip>
#include <armadillo>
#include <cstdlib>
#include <sstream>
#include <string>
//#include "mpi.h"

//For debugging:
// compile with: g++ solar_system.cpp -o main1 -larmadillo -llapack -lblas
// execute with ./main1

//For paralellization
//mpicxx  -o main_mpi.x  main.cpp -std=c++11
//mpiexec -n 2 ./main_mpi.x

std::ofstream ofile;
double pi = 3.14159265359;


void planet(arma::Col <double> &x, arma::Col <double> &y, arma::Col <double> &vx,
            arma::Col <double> &vy){
  double a,r,ax,ay;
  double GM = 4*pi*pi;

  int n = x.n_elem;

  arma::Col <double> t = arma::vec(n);
  double tmin = 0;
  double tmax = 10;
  double dt = (tmax-tmin)/n;
  for (int i=0; i<n; i++){
    t(i)=i*dt;
  }


  for (int i=1; i<n; i++){
    r = sqrt(x(i-1)*x(i-1) + y(i-1)*y(i-1));
    a = GM / (r*r);

    ax = -a*x(i-1);
    ay = -a*y(i-1);


    vx(i) = vx(i-1) + ax*dt;
    vy(i) = vy(i-1) + ay*dt;

    x(i) = x(i-1) + vx(i-1)*dt;
    y(i) = y(i-1) + vy(i-1)*dt;

  }

  std::string fileout = "Orbit.txt";
  ofile.open(fileout);
  ofile << std::setiosflags(std::ios::showpoint | std::ios::uppercase);
  for (int i=0; i<n; i++){
    ofile << std::setw(15) << x(i);
    ofile << std::setw(15) << y(i) << "\n";
  }
  //ofile << std::setw(15) << y << "\n";
  ofile.close();



} // end of function planet()




int main(){
  int len = 1000;

  arma::Col <double> x = arma::vec(len); x(0)=1;
  arma::Col <double> y = arma::vec(len); y(0)=0;
  arma::Col <double> vx = arma::vec(len); vx(0)=0;
  arma::Col <double> vy = arma::vec(len); vy(0)=1;

  planet(x,y,vx,vy);




  return 0;
} // end of function main()
