#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vi a(3*n);
  rep(i,0,3*n) cin >> a[i];

  const int N = 2123;
  const int inf = 1e9;

  vi bst(N, -inf);
  vvi dp(N, vi(N, -inf));
  queue<tuple<int,int,int>> q;
  int mx = 0, extra = 0;

  dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
  bst[a[0]] = bst[a[1]] = 0;

  auto upd = [&](int i, int j, int v) {
    q.emplace(i, j, v);
  };

  for (int i = 2; i+2 < 3*n; i += 3) {
    sort(a.begin()+i, a.begin()+i+3);

    if (a[i] == a[i+2]) { // just pick these three
      ++extra;
      continue;
    }

    if (a[i] == a[i+1])
      rep(j,1,N)
        upd(j, a[i+2], dp[a[i]][j]+1);


    if (a[i+1] == a[i+2])
      rep(j,1,N)
        upd(j, a[i], dp[a[i+1]][j]+1);

    // try to match with prev pair
    upd(a[i], a[i+1], max(dp[a[i+2]][a[i+2]]+1, mx));
    upd(a[i], a[i+2], max(dp[a[i+1]][a[i+1]]+1, mx));
    upd(a[i+2], a[i+1], max(dp[a[i]][a[i]]+1, mx));

    rep(j,0,N) rep(k,0,3) upd(a[i+k], j, bst[j]);

    while (not q.empty()) {
      auto [i, j, v] = q.front(); q.pop();
      ckmax(dp[i][j], v);
      ckmax(dp[j][i], v);
      ckmax(bst[i], v);
      ckmax(bst[j], v);
      ckmax(mx, v);
    }

  }

  ++dp[a[3*n-1]][a[3*n-1]];

  int ans = 0;
  rep(i,0,N) ckmax(ans, *max_element(all(dp[i])));
  cout << ans+extra << '\n';

}