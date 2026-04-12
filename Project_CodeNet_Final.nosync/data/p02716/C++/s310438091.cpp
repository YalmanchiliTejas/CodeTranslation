#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

ll pre[200005], suf[200005];
ll dp[200005][3];

void solve(int tc) {
  cin >> n;
  ai(a, n);

  f0r(i, n) {
    pre[i] = a[i];
    if (i >= 2) pre[i] += pre[i - 2];
  }

  f0rd(i, n - 1) {
    suf[i] = a[i];
    if (i + 2 < n) suf[i] += suf[i + 2];
  }

  if (n % 2 == 0) {
    ans = max(pre[n - 2], pre[n - 1]);
    f1r(pos, -1, n - 2) {
      if (pos % 2) continue;
      ll v = 0;
      if (pos > -1) v += pre[pos];
      if (pos + 3 < n) v += suf[pos + 3];
      ans = max(ans, v);
    }
  } else {
    ans = pre[n - 2];
    f1r(pos, -1, n - 2) {
      ll v = 0;
      if (pos > -1) v += pre[pos];
      if (pos + 3 < n) v += suf[pos + 3];
      ans = max(ans, v);
    }
    f1r(pos, -1, n - 3) {
      if (pos % 2) continue;
      ll v = 0;
      if (pos > -1) v += pre[pos];
      if (pos + 4 < n) v += suf[pos + 4];
      ans = max(ans, v);
    }

    f0r(i, n) f0r(j, 3) dp[i][j] = -mod * mod;
    f0r(i, n) {
      dp[i][i % 2] = pre[i];
      f1r(j, 1, 3) {
        if (i > 1) dp[i][j] = a[i] + dp[i - 2][j];
        if (i > 2) dp[i][j] = max(dp[i][j], a[i] + dp[i - 3][j - 1]);
      }
    }

    ans = max(ans, dp[n - 2][1]);
    ans = max(ans, dp[n - 1][2]);
  }

  cout << ans << '\n';
}

int main() {
  send help

  // usaco("file");

  int tc;
  tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
} 