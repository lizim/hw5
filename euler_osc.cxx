#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
  
  const int M = 2;
  double yf[M], yb[M];
  
  double t = 0;
  double tmax = 20*M_PI;
  double dt = M_PI/10;
//   double dt = M_PI/100;
  double N = tmax/dt + 1;
  
  double tempf, tempb;
  
  //initial conditions for Euler Forward and Backward
  yf[0] = 1;
  yf[1] = 0;
  yb[0] = 1;
  yb[1] = 0;
  
  ofstream out ("hw5_output_10.dat");
  
  out << t << "\t" << yf[0] << "\t" << yb[0] << "\t" << cos(0) << endl; 
  
  for(int i=0; i<N; i++){
  
    t += dt;
    
    //forward
    tempf = yf[0];
    yf[0] += dt * yf[1];
    yf[1] -= dt * tempf;
    
    //backward
    tempb = yb[0];
    
    // Variable fuer bessere Leserlichkeit
    double a = 1.0/(1 + dt*dt);
    
    yb[0] = a * yb[0] + a * dt * yb[1];
    yb[1] = a * yb[1] - a * dt * tempb;
        
    out << t << "\t" << yf[0] << "\t" << yb[0] << "\t" << cos(t) << endl;
  }
  
  out.close();
  
  return 0;
}
