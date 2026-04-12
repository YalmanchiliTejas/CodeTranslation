#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int main(){
  ll N, K;
  cin >> N >> K;
  if(K == 0){
    cout << N*N << endl;
    return 0;
  }
  ll ans = 0;
  FOR(i, 1, N+1){
    if(i <= K) continue;
    ans += (N/i)*(i-K);
    if(N % i >= K){
      ans += N % i - K+1;
    }
  }
  cout << ans << endl;
  return 0;
}
