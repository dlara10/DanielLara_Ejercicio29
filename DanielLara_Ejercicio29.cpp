#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    double c = 0.5;
    double c1 = c;
    double dp;
    double ratio = c*c/(c1*c1);
    int i, j, t;
    double deltat = 0.01;
    double deltax = 0.01;
    double tmax = 6;
    int iteracion = 0;
    double Told[101][600];
    double Tnew[101][600];
    double x;
    ofstream outfile;

    /*Inicializa*/
    for(i=0;i<600;i++){
        Told[0][i] = 0;
        Told[101][i]= 0;
        Tnew[0][i] =0;
        Tnew[101][i] =0;
    }
    for ( i = 1; i <= 600;i++){
       x= (i-1)*deltax;
    if ( x < 0.7) {
        Told[i][0] = (0.05/0.7)*x;
    }      
    else {
        Told[i][0] = (0.05/0.3)*(1-x);
    }
        
    }
  outfile.open("onda.dat");
  while(t < tmax){
    for(i=1;i<600;i++){
        for(j = 1; j<101; j++){
            dp = ratio*(Told[j+1][i] - 2.*Told[j][i] + Told[j-1][i]);
            Tnew[j][i+1] = 2.*Told[j][i] - Told[j][i-1] + c*dp;
        }
    }
    for(i=0;i<600;i++){
        for(j=0;j<101;j++){
      outfile << Tnew[j][i] << " ";
        }
    }
    outfile << "\n";

    for(i=1;i<600;i++){
        for(j = 1; j<101; j++){
          Told[j][i] = Tnew[j][i];
    }
    }
    t = t + deltat;
  }
  outfile.close();
  return 0;
}
