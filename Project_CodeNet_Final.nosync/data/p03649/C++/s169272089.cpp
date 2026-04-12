#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, string s = "\n") { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ")
{ if (!v.size()) puts(""); rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

signed main()
{
  int n = in();
  vector<lint> a;

  rep(i, n) a.pb(in());

  lint ans = 0;
  while (true) {
    bool f = true;
    rep(i, n) if (a[i] >= n) f = false;
    if (f) break;

    lint cnt = 0;
    rep(i, n) {
      cnt += max(0ll, a[i]) / n;
    }
    rep(i, n) {
      lint d = max(0ll, a[i]) / n;
      a[i] = a[i] - d * n + (cnt - d);
    }

    ans += cnt;
  }

  print(ans);
}
