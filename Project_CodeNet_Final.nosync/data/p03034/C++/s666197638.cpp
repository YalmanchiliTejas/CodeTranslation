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

vector<ll> s;

template<typename T>
T gcd(T a, T b) {
  if(a > b)return gcd(b, a);
  if(a == 0)return b;
  return gcd(b % a, a);
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  INT(n);
  s.resize(n);
  cin >> s;
  vector<vector<ll>> gsum(n);
  FOR(i, 1, n - 1){
    ll curr = 0;
    for(int j = 0; j < n; j+=i){
      curr += s[j];
      gsum[i].pb(curr);
    }
  }
  vector<vector<ll>> grsum(n);
  FOR(i, 1, n - 1){
    ll curr = 0;
    for(int j = 0; j < n; j+=i){
      curr += s[n-1-j];
      grsum[i].pb(curr);
    }
  }
  ll res = s[n-1];
  for(int a = 1; a <= n - 1; a++){
    int r = n - a - 1;
    for(int i = 1; i * i <= r; i++){
      if(r % i != 0)continue;
      int b = a - i;
      bool ok = true;
      if(b <= 0)ok = false;
      int k = (n - a - 1) / i;
      if(a % (a - b) == 0){
        if(- k <= a / (a - b) && a / (a - b) <= k)ok = false;
      }
      if(ok){
        ll tmp = 0;
        tmp += grsum[a-b][k];
        tmp += gsum[a-b][k];
        res = max(res, tmp);
      }

      ok = true;
      b = a - r / i;
      if(b <= 0)ok = false;
      k = (n - a - 1) / (r / i);
      if(a % (a - b) == 0){
        if(- k <= a / (a - b) && a / (a - b) <= k)ok = false;
      }
      if(ok){
        ll tmp = 0;
        tmp += grsum[a-b][k];
        tmp += gsum[a-b][k];
        res = max(res, tmp);
      }
    }
  }
  cout << res << endl;
  return 0;
}

