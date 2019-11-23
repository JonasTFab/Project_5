#include <iostream>
#include <armadillo>
//#include "mpi.h"

//For debugging:
// compile with: g++ solar_system.cpp -o main1 -larmadillo -llapack -lblas
// execute with ./main1

//For paralellization
//mpicxx  -o main_mpi.x  main.cpp -std=c++11
//mpiexec -n 2 ./main_mpi.x

double pi = 3.14159265359;


void planet(double x_init, double y_init, double vx_init, double vy_init){
  double a,r,ax,ay;
  int len = 100;

  arma::Col <double> t = arma::vec(len);
  double tmin = 0;
  double tmax = 10;
  for (int i=0,i<len, i++){
    t(i)=i*dt;
  }
  arma::Col <double> x = arma::vec(len); x(0)=x_init;
  arma::Col <double> y = arma::vec(len); y(0)=y_init;
  arma::Col <double> vx = arma::vec(len); vx(0)=vx_init;
  arma::Col <double> vy = arma::vec(len); vy(0)=vy_init;

  for (int i=1; i<len; i++){
    r = sqrt(x(i-1)*x(i-1)+y(i-1)*y(i-1));
    a = 4*pi*pi/(r*r);

    ax = a*x(i-1);
    ay = a*y(i-1);

    vx(i) = vx(i-1) + ax*t(i);
    vy(i) = vy(i-1) + ay*t(i);

    x(i) = x(i-1) + vx(i)*t(i) * 0.5*ax*t(i)*t(i);
    y(i) = y(i-1) + vy(i)*t(i) * 0.5*ay*t(i)*t(i);


  }

} // end of function planet()




int main(){
  double x0,y0,vx0,vy0;
  x0,y0,vx0,vy0 = 1,0,0,1;

  planet(x0,y0,vx0,vy0);




  return 0;
} // end of function main()
