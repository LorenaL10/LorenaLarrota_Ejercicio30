#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
   int m=100;
    double c=1;
    double t_max=2.0;
    double t=0.0;
    double u[m+1];
    double u_final[m+1];
    double u_inicial[m-1];
    double delta_t=0.01;
    double delta_x=0.01;
    double beta= c*delta_t/delta_x;
    double x;
    int n=t_max/delta_t;
    
    ofstream outfile;

    // inicializo
  for(int i=0; i<m; i++){
    x=i*delta_x;
    u_final[i]=exp(-300*(x-0.12)*(x-0.12));
    u_inicial[i]=exp(-300*(x-0.12-c*t_max)*(x-0.12-c*t_max));
    u[i]=0;
  }
    
outfile.open("onda.txt");    
while (1<t_max){
        for (int i=0; i<m-1; i++) {
        u[i+1] = u_inicial[i]-0.25*beta*(u_inicial[i+1]-u_inicial[i-1])+(beta*beta/8)*[(u_inicial[i+1]+u_inicial[i])*(u_inicial[i+1]*u_inicial[i+1]+u_inicial[i]*u_inicial[i])- (u_inicial[i]+u_inicial[i-1])*(u_inicial[i]*u_inicial[i]+u_inicial[i-1]*u_inicial[i-1])];
        u[0]=0;
        u[m-1]=0;
        u_inicial[i]=u[i];
        }
       
    
    for(int j=0;j<m-1;j++){
      double pos = 0.01*j;
      double y = u[j];
        outfile << y << " ";    
    }
    
    outfile << "\n";
    t=t+delta_t;
}
    
    outfile.close();
    return 0;
    
}
