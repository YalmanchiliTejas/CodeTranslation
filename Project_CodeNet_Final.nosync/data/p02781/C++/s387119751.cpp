#pragma region

#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _rep3(i, begin, end) for (register int i = (begin), i##_end = (end); i < i##_end; i++)
#define _irep3(i, begin, end) for (register int i = (end)-1, i##_begin = (begin); i >= i##_begin; i--)
#define _rep2(i, n) _rep3(i, 0, n)
#define _irep2(i, n) _irep3(i, 0, n)
#define _overload3(_1, _2, _3, name, ...) name
#define rep(...) _overload3(__VA_ARGS__, _rep3, _rep2, )(__VA_ARGS__)
#define irep(...) _overload3(__VA_ARGS__, _irep3, _irep2, )(__VA_ARGS__)
#define out(x) cout << (x) << '\n';
#define debug(x) cerr << #x << " = " << (x) << " (line: " << __LINE__ << ") " << endl;

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &pair) {
  cin >> pair.first >> pair.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[ ";
  rep(i, vec.size()) i == 0 ? os << vec[i] : os << ", " << vec[i];
  os << " ]";
  return os;
}

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

void init() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10) << boolalpha;
}

#pragma endregion

#define MOD 1000000007
#define INF 2147483647

const int MAX = 200;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll a, ll b, ll mod = MOD) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  init();

  COMinit();

  string N;
  int K;
  cin >> N >> K;

  vvl dp(4, vl(102, 0));
  dp[0][0] = 1;
  rep(i, 101) dp[1][i + 1] = 9;
  rep(i, 100) dp[2][i + 2] = 9 * 9 * (i + 1);
  rep(i, 99) dp[3][i + 3] = 9 * 9 * 9 * (i + 1) * (i + 2) / 2;

  vvl sum(4, vl(103, 0));
  rep(i, 4) {
    rep(j, 102) sum[i][j + 1] = sum[i][j] + dp[i][j];
  }

  int digits = N.length();

  vi zero(digits + 1, 0);
  rep(i, digits) zero[i + 1] = zero[i] + (N[i] == '0');

  ll ans = 0;
  rep(i, digits) {
    int num = N[i] - '0';
    int digit = digits - i;
    int ze = zero[i];
    rep(j, i == digits - 1 ? (num + 1) : num) {
      if (i == 0 && j == 0) {
        ans += sum[K][digit] - sum[K][0];
        continue;
      }
      int n = digit - 1;
      int non_zero = n - (digits - K - (ze + (j == 0)));
      if (non_zero < 0 || non_zero > n) continue;
      ans += modpow(9, non_zero) * COM(n, non_zero) % MOD;
      ans %= MOD;
    }
  }

  out(ans % MOD);
}
