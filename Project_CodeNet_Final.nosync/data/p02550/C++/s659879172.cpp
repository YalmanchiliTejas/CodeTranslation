#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,X,M;
  cin >> N >> X >> M;
  vector<long long> V(M,-1);
  
  long long sum = 0;
  for(int i=0;i<N;i++){
    if(V[X]==-1){
      V[X] = i;
      sum += X;
      X *= X;
      X %= M;
    }
    else{
      long long k = i - V[X], Ws = 0;
      vector<long long> W(k);
      for(long long j=0;j<M;j++){
        if(V[X]<=V[j] && V[j]<i){
          W[V[j]-V[X]] = j;
          Ws += j;
        }
      }
      
      sum += Ws * ((N-i)/k);
      for(int j=0;j<(N-i)%k;j++){
        sum += W[j];
      }
      break;
    }
  }
  
  cout << sum << endl;
  return 0;
}
