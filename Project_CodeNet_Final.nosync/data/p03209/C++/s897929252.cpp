#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,N) for(i=0;i<N;i++)
vector<string> mem;
int N;
ll X;
vector<ll> L,P;

ll eat(int n, ll X_){
  if(X_ == L[n]) return P[n];
  else if(X_<=0) return 0;
  else if(X_> L[n]/2) return P[n-1]+1+eat(n-1,X_-2-L[n-1]);
  else return eat(n-1,X_-1);
}

int main(void){
  cin >> N >> X;
  L.resize(N+1);
  P.resize(N+1);
  int i;
  L[0] = 1;
  P[0] = 1;
  REP(i,N){
    L[i+1] = 2*L[i] + 3;
    P[i+1] = 2*P[i] + 1;
  }
  cout << eat(N,X) << endl;
  return 0;
}