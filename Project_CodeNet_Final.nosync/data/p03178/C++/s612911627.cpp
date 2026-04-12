#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
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

int dp[10001][2][101];

signed main(){
  string k;
  int D;
  cin >> k >> D;
  int n = sz(k);

  dp[0][0][0] = 1;
  rep(i, 0, n) rep(j, 0, 2) rep(l, 0, 101){
    int d = j ? 9 : k[i]-'0';
    rep(x, 0, d+1){
      (dp[i+1][j||x<d][(l+x)%D] += dp[i][j][l]) %= mod;
    }
  }

  cout << (dp[n][0][0]+dp[n][1][0]+mod-1)%mod << endl;

  return 0;
}

