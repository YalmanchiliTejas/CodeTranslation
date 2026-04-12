#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define in(x) cin >> x
#define inv(x) for (auto &t : (x)) cin >> t
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define outv(x) for (auto &t : (x)) out((x))
#define outsv(x) for (auto &t : (x)) outs((x))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i++)
#define repf(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define repfr(i, x, n) for (int i = (int)(n)-1; i < (int)(x); i++)
#define sz(x) ((int)(x).size())
#define sz(x) ((int)(x).size())
#define inf 1e9
template <class T> bool chmax(T &a, const T &b)
{if (a < b) {a = b;return 1;}return 0;}
template <class T> bool chmin(T &a, const T &b)
{if (b < a) {a = b;return 1;}return 0;}
using ll = int64_t;

void Main() {
  int x, y, z;
  in(x);
  in(y);
  in(z);

  int space = y + z;
  out((x - z) / space);

  return;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
