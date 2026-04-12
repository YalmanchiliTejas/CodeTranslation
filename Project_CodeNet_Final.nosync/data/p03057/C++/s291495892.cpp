#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2>
inline bool cmn (T1& a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
inline bool cmx (T1& a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
constexpr int md = 1e9 + 7;
inline void mad(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void msb(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b) {
  return (int)((long long)a * b % md);
}
template<typename T>
class run_length_encoding {
  vector<pair<int, T>> rle;
  public:
    run_length_encoding(
        vector<T> input
      ) :
      rle()
      {
        int cnt = 0;
        for (auto it = input.begin(); it != input.end(); it++) {
          auto jt = next(it); cnt++;
          if (jt == input.end() || *it != *jt) {
            rle.emplace_back(cnt, *it);
            cnt = 0;
          }
        }
      }
    auto const& code () const {return rle;}
};
int main() {
  int n, m; string s;
  cin >> n >> m >> s;
  vector<int> a(m);
  for (int i = 0; i < m; i++) a[i] = s[0] == s[i];
  auto rle = run_length_encoding<int>(a).code();
  if (rle.size()  == 1) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      mad(dp[i], dp[i - 1]);
      mad(dp[i], dp[i - 2]);
    }
    for (int i = n; i >= 1; i--) msb(dp[i], dp[i - 1]);
    int ret = 1;
    for (int i = 1; i < n; i++) {
      mad(ret, mul(i + 1, dp[n - i]));
    }
    cout << ret << endl;
    return 0;
  }
  if (n & 1) {
    cout << 0 << endl;
    return 0;
  }
  n >>= 1;
  int k = n;
  for (auto it = rle.begin(); it < rle.end() - 1; it += 2) {
    int m = it->first;
    if (m & 1) cmn(k, (m + 1) >> 1);
    else if (it == rle.begin()) cmn(k, (m + 2) >> 1);
  }
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    mad(dp[i], dp[i - 1]);
    mad(dp[i], dp[i - 1]);
    if (i - k - 1 >= 0) msb(dp[i], dp[i - k - 1]);
  }
  for (int i = n; i >= 1; i--) msb(dp[i], dp[i - 1]);
  int ret = 0;
  for (int i = 0; i < k; i++) {
    mad(ret, mul(i + 1, dp[n - i]));
  }
  mad(ret, ret);
  cout << ret << endl;
  return 0;
}