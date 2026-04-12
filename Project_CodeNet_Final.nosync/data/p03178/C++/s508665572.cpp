#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

signed main()
{
  string k;
  int d;
  cin >> k >> d;
  int n = k.size();
  
  vector<vvi> dp(n+1, vvi(2, vi(d)));
  dp[0][0][0] = 1;
  rep(i, 0, n) rep(j, 0, 2) rep(l, 0, d){
    int x = j ? 9 : k[i]-'0';
    rep(y, 0, x+1){
      (dp[i+1][j|y<x][(l+y)%d] += dp[i][j][l]) %= mod;
    }
  }

  int ans = (dp[n][0][0]+dp[n][1][0]-1+mod) % mod;
  cout << ans << endl;

  return 0;
}
