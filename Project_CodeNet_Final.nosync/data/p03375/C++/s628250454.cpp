#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

struct Combination
{
  vector< int64_t > mfact, rfact;
  int mod;

  Combination(int sz, int mod) : mod(mod), mfact(sz + 1), rfact(sz + 1)
  {
    mfact[0] = 1;
    for(int i = 1; i < mfact.size(); i++) {
      mfact[i] = mfact[i - 1] * i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for(int i = sz - 1; i >= 0; i--) {
      rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
  }

  int64_t fact(int k) const
  {
    return (mfact[k]);
  }

  int64_t pow(int64_t x, int64_t n) const
  {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }


  int64_t pow2(int64_t x, int64_t n) const
  {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod - 1;
      (x *= x) %= mod - 1;
      n >>= 1;
    }
    return (ret);
  }


  int64_t inv(int64_t x) const
  {
    return (pow(x, mod - 2));
  }

  int64_t P(int n, int r) const
  {
    if(r < 0 || n < r) return (0);
    return (mfact[n] * rfact[n - r] % mod);
  }

  int64_t C(int p, int q) const
  {
    if(q < 0 || p < q) return (0);
    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
  }

  int64_t H(int n, int r) const
  {
    if(n < 0 || r < 0) return (0);
    return (r == 0 ? 1 : C(n + r - 1, r));
  }
};
int main() {
  int N, M;
  cin >> N >> M;
  Combination uku(N, M);
  int64 ret = 0;

  auto dp2 = make_v< int >(N + 1, N + 1);
  dp2[0][0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = i; j >= 0; j--) {
      dp2[i + 1][j] += dp2[i][j];
      dp2[i + 1][j] %= M;
      dp2[i + 1][j] += 1LL * dp2[i][j] * j % M;
      dp2[i + 1][j] %= M;

      dp2[i + 1][j + 1] += dp2[i][j];
      dp2[i + 1][j + 1] %= M;
    }
  }
  auto ways = [&](int sz) {
    /*
    vector< int64 > dp(sz + 1);
    dp[0] = 1;
    for(int i = 0; i < sz; i++) {
      vector< int64 > dp2(dp);
      for(int j = 0; j < sz; j++) {
        // すでに作ったやつのうちいずれかを使う
        dp2[j] += dp[j] * j % M;
        dp2[j] %= M;
        // 新しく作る
        dp2[j + 1] += dp[j];
        dp2[j + 1] %= M;
      }
      dp.swap(dp2);
    }
     */
    int64 all = 0;
    for(int i = 0; i <= sz; i++) {
      all += dp2[sz][i] * uku.pow(2, (N - sz) * i) % M;
      all %= M;
    }
    all *= uku.pow(2, uku.pow2(2, N - sz));
    all %= M;
    return all;
  };

  for(int i = 0; i <= N; i++) {
    int64 add = uku.C(N, i) * ways(i) % M;
    if(i & 1) add = M - add;
    (ret += add) %= M;
  }
  cout << ret << endl;
}
