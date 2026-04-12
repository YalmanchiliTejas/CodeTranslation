#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
template<typename T>
T add(T x) {
  return x;
}
template<typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= mod)
    res -= mod;
  return res;
}
template<typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, mod - add(y...));
}
template<typename T, typename... Ts>
void udd(T& x, Ts... y) {
  x = add(x, y...);
}
template<typename T, typename... Ts>
void uub(T& x, Ts... y) {
  x = sub(x, y...);
}
template<typename T>
T mul(T x) {
  return x;
}
template<typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(int a, ll deg) {
  int r = 1;
  while (deg) {
    if (deg & 1)
      uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
int inv(int x) {
  assert(x);
  return bin(x, mod - 2);
}

const int maxn = 105;
int h[maxn];
int d[maxn][maxn];
vector<int> hs;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    hs.push_back(h[i]);
  }
  hs.push_back(0);
  hs.push_back(1e9 + 7);
  sort(hs.begin(), hs.end());
  hs.erase(unique(hs.begin(), hs.end()), hs.end());
  int last = hs.size() - 2;
  d[0][last] = 1;
  for (int i = 0; i < n; ++i) {
    //for (int j = 0; j <= last; ++j) {
      //cerr << d[i][j] << ' ';
    //}
    //cerr << '\n';
    for (int j = 0; j <= last; ++j) {
      if (i && h[i] <= h[i - 1]) {
        int nj = hs[j] < h[i] ? j : last;
        udd(d[i + 1][nj], d[i][j]); //inv
        if (nj == last) {
          udd(d[i + 1][nj], d[i][j]); //copy
        }
      } else {
        int ph = i ? h[i - 1] : 0;
        if (j != last) {
          udd(d[i + 1][j], mul(d[i][j], bin(2, h[i] - ph)));
        } else {
          udd(d[i + 1][last], mul(2, d[i][j]));
          int from = lower_bound(hs.begin(), hs.end(), ph) - hs.begin();
          for (int nj = from; hs[nj] < h[i]; ++nj) {
            int ways = bin(2, h[i] - hs[nj]);
            int bad = bin(2, h[i] - hs[nj + 1] + 1);
            if (i || nj > 0) {
              uul(ways, 2);
            }
            //if (d[i][j]) {
              //cerr << "wb " << ways << ' ' << bad << '\n';
            //}
            uub(ways, bad);
            udd(d[i + 1][nj], mul(d[i][j], ways));
          }
        }
      }
    }
  }
    //for (int j = 0; j <= last; ++j) {
      //cerr << d[n][j] << ' ';
    //}
    //cerr << '\n';
  int res = 0;
  for (int j = 0; j <= last; ++j) {
    udd(res, d[n][j]);
  }
  cout << res << '\n';
}
