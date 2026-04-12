#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,S;
  cin>>N>>S;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  ll ans = 0;
  vector<ll> dp(3005,0);
  dp[0]++;
  dp[v[0]]++;
  ans += dp[S];
  rep(i,N-1){
    dp[0]=(dp[0]+1)%mod;
    for(int j = 3004; j >= 0; j--){
      if(j-v[i+1]>=0) dp[j] = (dp[j]+dp[j-v[i+1]])%mod;
    }
    ans = (ans + dp[S])%mod;
  }
  cout<<ans<<endl;
}