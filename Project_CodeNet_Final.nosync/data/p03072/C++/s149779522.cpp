#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)

using namespace std;
using ll = long long;

template<typename T=int>
T in(){T x; cin >> x; return (x);}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N=in();
  vector<ll> A(N);
  REP(i,N) A[i]=in();
  
  int num=0,mh=0;
  for(int i=0;i<N;i++){
    if(A[i]>=mh){
      num++;
      mh = A[i];
    }
  }
  cout << num << endl;
  
  return 0;
}