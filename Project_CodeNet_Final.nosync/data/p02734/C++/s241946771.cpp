#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int dp[3005], n, s, x;
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n >> s;
  int ans = 0;
  f(i,0,n){
    
    cin >> x;
    dp[0]++;
    for(int j = s; j >= x; --j){
      dp[j] += dp[j-x];
      if(dp[j] >= MOD)dp[j]-=MOD;
    }
    ans += dp[s];
    if(ans>=MOD)ans-=MOD;
  }
  cout<<ans<<'\n';

  return 0;
}
