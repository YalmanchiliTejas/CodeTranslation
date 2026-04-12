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
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}
} fast_io_;


int main(int argc, char const* argv[])
{
  string s; cin >> s;
  vector<int> v(sz(s)); rep(i, sz(s))v[i] = int(s[i] - '0');
  int k; cin >> k;
  ll res1 = 0, res2 = 0, res3 = 0;
  for(int i = 0; i < sz(s); i++){
    if(i == 0)res1 += v[0];
    else res1 += 9;
  }
  vector<int> base(sz(s), 0);
  for(int i = 0; i < sz(s); i++){
    for(int j = i + 1; j < sz(s); j++){
      if(i == 0){
        for(int k = 1; k <= 9; k++){
          for(int l = 1; l <= 9; l++){
            base[i] = k;
            base[j] = l;
            if(base <= v)++res2;
            base[i] = 0;
            base[j] = 0;
          }
        }
      }else{
        res2 += 81;
      }
    }
  }
  for(int i = 0; i < sz(s); i++){
    for(int j = i + 1; j < sz(s); j++){
      for(int k = j + 1; k < sz(s); k++){
        if(i == 0){
          FOR(l, 1, 10){
            FOR(m, 1, 10){
              FOR(p, 1, 10){
                base[i] = l;
                base[j] = m;
                base[k] = p;
                if(base <= v)++res3;
                base[i] = 0;
                base[j] = 0;
                base[k] = 0;
              }
            }
          }
        }else{
          res3 += 81 * 9;
        }
      }
    }
  }
  if(k == 1)cout << res1 << endl;
  else if(k == 2)cout << res2 << endl;
  else cout << res3 << endl;
  return 0;
}
