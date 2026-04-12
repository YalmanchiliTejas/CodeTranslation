#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9
const int mod = 1e9+7;
ll N, X;
vector<ll> P(51,0), PB(51,0);

ll solve(int L, ll ray){
  if(L==0){
    if(ray <= 0){
      return 0;
    }
    else{
      return 1;
    }
  }
  else if(ray <= 1+PB[L-1]){
    return solve(L-1, ray-1);
  }
  else{
    return P[L-1] + 1 + solve(L-1, ray-2-PB[L-1]);
  }
}

int main(){
  cin >> N >> X;
  P[0] = PB[0] = 1;
  FOR(i, 1, 51){
    P[i] = P[i-1]*2+1;
    PB[i] = PB[i-1]*2+3;
  }

  cout << solve(N, X) << endl;

  
  return 0;
}
