#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())

#define REP(a, b) for (int a = 0; a < (b); a++)
#define FOR(a, b, c) for (int a = (b); a <= (c); a++)
#define REPD(a, b) for (int a = (b) - 1; a >= 0; a--)
#define FORD(a, b, c) for (int a = (b); a >= (c); a--)

#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))

#ifdef __DEBUG
#define debug if (true)
#else
#define debug if (false)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;
template <typename T> using VVV = vector<VV<T>>;

template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2> &p) {
  return is >> p.fi >> p.se;
}

const int N = 3003;

int n;
int a[N];
ll dp[N][N];
bool visit[N][N];

ll go(int l, int r) {
  if (l > r) return 0;
  if (visit[l][r]) return dp[l][r];
  int turn = (n - (r - l + 1)) % 2;
  if (turn == 0) {
    dp[l][r] = max(a[l] + go(l + 1, r), a[r] + go(l, r - 1));
  } else {
    dp[l][r] = min(go(l + 1, r) - a[l], go(l, r - 1) - a[r]);
  }
  visit[l][r] = true;
  return dp[l][r];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  REP(i, n) cin >> a[i];
  cout << go(0, n - 1) << endl;
}
