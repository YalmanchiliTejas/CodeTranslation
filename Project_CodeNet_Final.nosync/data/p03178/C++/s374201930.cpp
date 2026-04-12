#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define fs first
#define sd second
template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
constexpr ll mod = 1000000007;


void solve(){
  string k; int d, n;cin >> k >> d;
  n = k.size();
  V3<ll> dp(2, V2<ll>(2,V<ll>(d,0)) );
  dp[0][1][0] = 1;
  FOR(i,0,n){
    FOR(j,0,d){
      dp[1][0][j] = 0;
      dp[1][1][j] = 0;
    }
    FOR(j,0,d){
      char c = k[i] - '0';
      FOR(k,0,10){
        (dp[1][0][(j+k)%d] += dp[0][0][j]) %= mod;
      }
      FOR(k,0,c){
        (dp[1][0][(j+k)%d] += dp[0][1][j]) %= mod;
      }
      (dp[1][1][(j+c)%d] += dp[0][1][j]) %= mod;
    }
    swap(dp[0],dp[1]);
  }
  cout << ((dp[0][0][0]+dp[0][1][0]-1+mod)%mod) << "\n";
}

int main(void){
    solve();
    return 0;
}