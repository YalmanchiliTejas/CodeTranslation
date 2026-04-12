#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main(){
  ios_base::sync_with_stdio (false);
  cin.tie(NULL);

  ll N;
  cin >> N;

  vl a(N, 0);

  FOR(i, 0, N) cin >> a[i];

  vector<vvl> dp(N+1, vvl(N+1, vl(2, 0)));

  FOR(i, 0, N){
    dp[i][i][0] = a[i];
    dp[i][i][1] = -a[i];
  }

  FOR(l, 1, N) FOR(p, 0, N-l){

    ll i = p;
    ll j = p+l;
    // Taro
    if(dp[i+1][j][1]+a[i] >= dp[i][j-1][1]+a[j]){
      dp[i][j][0] = dp[i+1][j][1]+a[i];
    }
    else{
      dp[i][j][0] = dp[i][j-1][1]+a[j];
    }

    // Other
    if(dp[i+1][j][0]-a[i] <= dp[i][j-1][0]-a[j]){
      dp[i][j][1] = dp[i+1][j][0]-a[i];
    }
    else{
      dp[i][j][1] = dp[i][j-1][0]-a[j];
    }

  }

  cout << dp[0][N-1][0] << endl;

}
