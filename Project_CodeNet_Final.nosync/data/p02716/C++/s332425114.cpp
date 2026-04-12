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
#define bit(n) (1LL<<(n))
// functions
template <typename T> void unique(T& c){c.erase(std::unique(c.begin(), c.end()), c.end());}
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
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}
} fast_io_;

ll calc_even(vector<ll> &a){
  int n = sz(a);
  vector<ll> acc = a;
  rep(i, n){
    if(i>1)acc[i] += acc[i-2];
  }
  ll res = -linf;
  chmax(res, max(acc[n-1], acc[n-2]));
  for(int i = 1; i < n - 2; i+=2){
    ll tmp = acc[i-1] + acc[n-1] - acc[i];
    chmax(res, tmp);
  }
  return res;
}

ll dp[200010][4];

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<ll> a(n); cin >> a;
  ll res = -linf;
  if(n % 2 == 0){
    res = calc_even(a);
  }else{
    vector<ll> at0(a.begin(), a.end() - 1);
    vector<ll> at1(a.begin() + 1, a.end());
    chmax(res, calc_even(at0));
    chmax(res, calc_even(at1));
    rep(i, n){
      rep(j, 4)dp[i][j] = -linf;
    }
    dp[0][0] = a[0];
    FOR(i, 1, n){
      rep(j, 4){
        if(i>1)chmax(dp[i][j], dp[i-2][j] + a[i]);
      }
      for(int j = 0; j < 3; j++){
        if(i>2)chmax(dp[i][j+1], dp[i-3][j] + a[i]);
      }
      for(int j = 0; j < 2; j++){
        if(i>3)chmax(dp[i][j+2], dp[i-4][j] + a[i]);
      }
    }
    chmax(res, dp[n-1][2]);
  }
  cout << res << endl;
  return 0;
}
