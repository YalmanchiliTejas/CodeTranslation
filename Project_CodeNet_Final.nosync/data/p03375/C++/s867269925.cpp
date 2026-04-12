// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define whole(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << "(" << itr->first << ", " << itr->second << ")"; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << "(" << itr->first << ", " << itr->second << ")"; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
//const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}
} fast_io_;


template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)(res * curr % mod);
    }
    curr = (T)(curr * curr % mod);
    tmp >>= 1;
  }

  return res;
}

struct Factorial{
  int n = 0;
  static const long long mod_default = 1e9 + 7;
  long long MOD = mod_default;
  vector<long long> fac;
  vector<long long> inv_;
  explicit Factorial(){}
  explicit Factorial(int n, long long mod_=mod_default): n(n), MOD(mod_){
    assert(MOD > 0 && n < MOD);
    fac.resize(n + 1);
    inv_.resize(n + 1);
    calc_factorial();
    calc_inv();
  }
  void calc_factorial(){
    fac[0] = 1;
    for(int i = 1; i <= n; i++){
      fac[i] = i * fac[i-1] % MOD;
    }
  }
  void calc_inv(){
    inv_[n] = power<long long>(fac[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--){
      inv_[i] = (i + 1) * inv_[i+1] % MOD;
    }
  }
  long long& operator[](size_t i){
    if((int)i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return fac[i];
  }
  long long inv(size_t i){
    if((int)i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return inv_[i];
  }
  long long comb(int n, int k){
    if(n < 0 || k < 0 || n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    res = res * inv_[k] % MOD;
    return res;
  }
  long long perm(int n, int k){
    if(n < 0 || k < 0 || n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    return res;
  }
  long long h(int n, int k){
    if(n == 0 && k == 0)return 1;
    return comb(n + k - 1, k);
  }
};

ll powpow(int k, ll mod){
  ll ex = power<ll>(2, k, mod - 1);
  ll res = power<ll>(2, ex, mod);
  return res;
}

ll d[3010][3010], e[3010][3010], f[3010][3010];

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  ll mod; cin >> mod;
  // d
  d[0][0] = 1;
  FOR(i, 1, n + 1){
    FOR(j, 1, i + 1){
      d[i][j] = (d[i-1][j] * j % mod + d[i-1][j-1]) % mod;
    }
  }
  /*// e
  for(int j = 1; j <= n; j++){
    rep(k, n + 1){
      ll x = power<ll>(2, k, mod);
      ll curr = x;
      e[j][k] = 0;
      for(int l = 1; l <= j; l++){
        (e[j][k] += curr * d[j][l] % mod) %= mod;
        curr = curr * x % mod;
      }
    }
  }*/
  Factorial fac(6010, mod);
  // f
  for(int k = 1; k <= n; k++){
    for(int m = 1; m <= n; m++){
      f[k][m] = 0;
      /*for(int l = 1; l <= k; l++){
        (f[k][m] += fac.comb(k, l) * d[l][m] % mod) %= mod;
      }*/
      //cerr << f[k][m] << " ";
      f[k][m] = (d[k][m] + d[k][m+1] * (m + 1) % mod) % mod;
      //cerr << f[k][m] << endl;
    }
  }
  // res
  ll res = powpow(n, mod);
  for(int i = 1; i <= n; i++){
    ll coef = fac.comb(n, i) * powpow(n - i, mod) % mod;
    /*ll tmp = 1;
    for(int j = 1; j <= i; j++){
      (tmp += fac.comb(i, j) * e[j][n-i] % mod) %= mod;
    }}*/
    ll x = power<ll>(2, n - i, mod);
    ll tmp = 1;
    ll curr = x;
    for(int m = 1; m <= i; m++){
      (tmp += curr * f[i][m] % mod) %= mod;
      curr = curr * x % mod;
    }
    if(i & 1)(res -= tmp * coef % mod) %= mod;
    else (res += tmp * coef % mod) %= mod;
  }
  if(res < 0)res += mod;
  cout << res << endl;
  return 0;
}
