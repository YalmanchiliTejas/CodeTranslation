#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, t;
  cin >>N;
  vector<int>A(N,0);
  t=N/2;
  for(int i=0; i<N; i++){
    int a;
    cin >>a;
    if(N%2==0){
      if(i%2==0) t+=i;
      else t-=i;
      A[t]=a;
    }
    else{
      if(i%2==0) t-=i;
      else t+=i;
      A[t]=a;
    }
  }
  for(int i=0; i<N; i++){
    if(i!=N-1) cout <<A[i] <<" ";
    else cout <<A[i] <<endl;    
  }
}