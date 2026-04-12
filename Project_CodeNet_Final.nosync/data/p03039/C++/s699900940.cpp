#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define fout(x) cout << fixed << setprecision(20) << x << endl
const int MOD = 1e9 + 7;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 1e-8;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto print = [](auto &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
};

template <int mod = 1000000007>
struct Combination {
  std::vector<long long> fac, finv, inv;
  Combination(const long long n) : fac(n + 1, 0), finv(n + 1, 0), inv(n + 1, 0) {
    for (long long i = 0; i < n + 1; ++i) {
      bool one_or_zero = i == 0 || i == 1;
      fac[i] = one_or_zero ? 1 : fac[i - 1] * i % mod;
      inv[i] = one_or_zero ? 1 : mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = one_or_zero ? 1 : finv[i - 1] * inv[i] % mod;
    }
    inv[0] = 0;
  }
  long long operator()(const long long n, const long long r) {
    if (n < r || n < 0 || r < 0)
      return 0;
    else if (n == r || r == 0)
      return 1;
    return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
  }
};


signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  Combination<MOD> comb(n * m);
  ll ans = 0;
  rep(i, n) rep(j, m) {
    ll tmp = ((n - i) * (m - j) % MOD) * (i + j) % MOD;
    tmp %= MOD;
    if(i != 0 && j != 0) tmp *= 2;
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }

  ans *= comb(n * m - 2, k - 2);
  out(ans % MOD);


  return 0;
}
