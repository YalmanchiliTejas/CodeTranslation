// includes
#include <bits/stdc++.h>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define vrep(v, i) for(int i = 0; i < (v).size(); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define FI first
#define SE second
#define dump(a, n) for(int i = 0; i < n; i++)cout << a[i] << "\n "[i + 1 != n];
#define dump2(a, n, m) for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cout << a[i][j] << "\n "[j + 1 != m];
#define bit(n) (1LL<<(n))
#define INT(n) int n; cin >> n;
#define LL(n) ll n; cin >> n;
#define DOUBLE(n) double n; cin >> n;
using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef complex<double> cd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}

template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)((ll)res * curr % mod);
    }
    curr = (T)((ll)curr * curr % mod);
    tmp >>= 1;
  }
  return res;
}

struct Factorial{
  int n;
  const int MOD = 1e9 + 7;
  vector<long long> fac;
  vector<long long> inv_;
  Factorial(int n): n(n){
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
    if(i < 0 || i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return fac[i];
  }
  long long inv(size_t i){
    if(i < 0 || i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return inv_[i];
  }
  long long comb(int n, int k){
    if(n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    res = res * inv_[k] % MOD;
    return res;
  }
  long long perm(int n, int k){
    if(n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    return res;
  }
  long long h(int n, int k){
    if(n == 0 && k == 0)return 1;
    return comb(n + k - 1, k);
  }
};

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  INT(n); INT(m); INT(k);
  Factorial fac(n * m * 2);
  ll res = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      ll tmp = 0;
      ll tmp1 = n * ((m - j - 1) * (ll)(m - j) % mod) % mod;
      ll tmp2 = n * ((j * (ll)(j + 1) % mod)) % mod;
      ll tmp3 = m * ((n - i - 1) * (ll)(n - i) % mod) % mod;
      ll tmp4 = m * ((i * (ll)(i + 1) % mod)) % mod;
      tmp = (tmp1 + tmp2 + tmp3 + tmp4) % mod;
      tmp = tmp * fac.inv(2) % mod;
      res = (res + tmp) % mod;
    }
  }
  res = res * fac.comb(n * m - 2, k - 2) % mod;
  res = res * fac.inv(2) % mod;
  cout << res << endl;
  return 0;
}

