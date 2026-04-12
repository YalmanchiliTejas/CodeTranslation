#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); }
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

const int N = 3005;
bool vis[N][N];
ll dp[N][N];
ll a[N], n;

ll solve(int l, int r) {
  if (l == r) return 0;
  if (!vis[l][r]) {
    dp[l][r] = max(
      a[r-1]-solve(l, r-1),
      a[l]-solve(l+1, r)
    );
    vis[l][r] = 1;
  }
  return dp[l][r];
}

int main() { // Emily <3
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(0, n) << nl;

  return 0;
}

