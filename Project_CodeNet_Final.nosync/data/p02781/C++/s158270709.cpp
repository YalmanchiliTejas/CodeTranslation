#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

int dp[101][4][2];

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;
  int x; cin >> x;

  dp[0][0][0] = 1;

  rep(i, si(s)) rep(j, 4) rep(k, 2) {
    int nd = s[i] - '0';

    rep(d, 10) {
      int ni = i+1, nj = j, nk = k;

      if (d != 0) ++nj;
      if (nj > x) continue;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }

      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  cout << dp[si(s)][x][0] + dp[si(s)][x][1] << endl;

  return (0);
}
