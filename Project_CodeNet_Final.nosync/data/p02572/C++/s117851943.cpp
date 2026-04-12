#include <bits/stdc++.h>
using namespace std;

int Exp(long long int exp_n,long long int exp_e, long long exp_mod);


int main(){
  long long int N,S=0,O=0;
  cin >> N;
  long long int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
    O=O+S*A[i];
    O=O%1000000007;
    S=S+A[i];
    S=S%1000000007;
  }
  cout << O <<endl;
}


int Exp(long long int exp_n,long long int exp_e, long long int exp_mod){
  long long int exp_o = 1;
  long long int exp_x=exp_n;
  long long int exp_tmp;
  
  while(0<exp_e){
    exp_tmp = exp_e/2;
    if(exp_e - exp_tmp*2 == 1){
      exp_o = exp_o*exp_x;
      if(exp_o>exp_mod){
        exp_o=exp_o%exp_mod;
      }
    }
    
    exp_x = exp_x*exp_x;
    if(exp_x>exp_mod){
      exp_x=exp_x%exp_mod;
    }
    exp_e = exp_tmp;
  }
  return exp_o;
}
