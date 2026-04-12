#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)

constexpr int mod = 998244353;
template<class T>using V = vector<T>;
template<class T>using V2 = V<V<T>>;

int main(){
  int n, s; cin >> n >> s;
  V<int> a(n); V2<ll> dp1(n+1,V<ll>(s+1,0)), dp2(n+1,V<ll>(s+1,0)), dp3(n+1,V<ll>(s+1,0));
  FOR(i,0,n) cin >> a[i];
  dp1[0][0] = 1;
  FOR(i,0,n){
    FOR(j,0,s+1) {
      dp1[i+1][j] = dp1[i][j];
    }
    FOR(j,0,s+1){
      dp2[i+1][j] += (dp1[i][j] + dp2[i][j]) % mod;
      if( (j+a[i]) <=s) (dp2[i+1][j+a[i]] += dp1[i][j]+dp2[i][j]) %= mod;
    }
    FOR(j,0,s+1){
      (dp3[i+1][j] += (dp3[i][j] + dp2[i][j]+dp1[i][j])%mod) %= mod;
      if( (j+a[i])<=s) (dp3[i+1][j+a[i]] += (dp1[i][j]+dp2[i][j]) ) %= mod;
    }
  }/*
  FOR(i,0,n+1){
    FOR(j,0,s+1) cout << dp1[i][j] << " ";
    cout << "\n";
  }cout << "\n";
  FOR(i,0,n+1){
    FOR(j,0,s+1) cout << dp2[i][j] << " ";
    cout << "\n";
  }cout << "\n";
  FOR(i,0,n+1){
    FOR(j,0,s+1) cout << dp3[i][j] << " ";
    cout << "\n";
  }*/
  cout <<  dp3[n][s];
}


