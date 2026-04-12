#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define MOD 1000000007
#define MAX 200010

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec)
    is >> x;
  return is;
}

long long int f[MAX] = {};
long long int rf[MAX] = {};

long long int pw(long long int x, long long int y) {
  long long ret = 1LL;

  for (long long int mask = 0; mask < 50; ++mask) {
    if (y >> mask & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
  }
  return ret % MOD;
}

long long int getComb(int n, int k) {
  if (k > n)
    return 0;
  long long int ret = f[n];
  ret = ret * rf[k] % MOD;
  ret = ret * rf[n - k] % MOD;
  return ret;
}

long long int initComb(int n) {
  rf[0] = f[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    f[i] = f[i - 1] * i % MOD;
    rf[i] = pw(f[i], MOD - 2);
  }
  return 1;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  ll N, M, K;
  cin >> N >> M >> K;

  initComb(MAX);

  ll ans = 0;

  FOR(d, 1, N) {
    ll e = (N - d) * M * M % MOD;
    e *= getComb(N * M - 2, K - 2);
    e %= MOD;
    e = e * d % MOD;
    ans += e;
    ans %= MOD;

    // cout << d << " " << e << endl;
  }

  FOR(d, 1, M) {
    ll e = (M - d) * N * N % MOD;
    e *= getComb(N * M - 2, K - 2);
    e %= MOD;
    e = e * d % MOD;
    ans += e;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
