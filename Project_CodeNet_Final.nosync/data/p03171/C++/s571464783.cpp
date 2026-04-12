#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (__typeof(a) i = (a); i < (b); ++i)
#define iter(it, c) \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int INF = ~(1 << 31);

#define sc second
#define fs first
#define pb push_back
#define mp make_pair

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T>
T smod(T a, T b) {
  return (a % b + b) % b;
}
// vim: cc=60 ts=2 sts=2 sw=2:

ll a[3010];

ll memo[3010][3010];
int cached[3010][3010];
ll dp(int l, int r) {
  if (l > r) return 0;
  if (cached[l][r]) return memo[l][r];
  cached[l][r] = true;
  ll bst = max(-dp(l, r - 1) + a[r], -dp(l + 1, r) + a[l]);
  return memo[l][r] = bst;
}

int main() {
  // code
  memset(cached, 0, sizeof(cached));

  int n;
  cin >> n;

  rep(i, 0, n) cin >> a[i];

  cout << dp(0, n - 1) << endl;

  // codend
}
