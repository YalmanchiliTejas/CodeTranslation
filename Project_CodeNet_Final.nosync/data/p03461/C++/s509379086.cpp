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
#define all(x) (x).begin(),(x).end()
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
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
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
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

template <typename T>
struct Graph {
  int n;
  vector<vector<T> > d;
  vector<vector<int> > path;
  Graph(int n): n(n) {
    d = vector<vector<T>>(n, vector<T>(n, numeric_limits<T>::max() / 10));
    path = vector<vector<int>>(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)d[i][i] = 0;
  }
  void warshall_floyd(){
    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
            path[i][j] = k;
          }
        }
      }
    }
  }
  void adde(int at, int to, T cost){
    d[at][to] = cost;
  }
  vector<T>& operator[](size_t i){
    return d[i];
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<ll>;


int d[11][11];
int f[101][101];


int main(int argc, char const* argv[])
{
  int a, b;
  cin >> a >> b;
  rep(i, a)rep(j, b)cin >> d[i][j];
  rep(i, 101){
    rep(j, 101){
      rep(x, a){
        rep(y, b){
          chmax(f[i][j], d[x][y] - (x + 1) * i - (y + 1) * j);
        }
      }
    }
  }

  rep(x, a){
    rep(y, b){
      int mini = inf;
      rep(i, 101){
        rep(j, 101){
          mini = min(mini, f[i][j] + (x + 1) * i + (y + 1) * j);
        }
      }
      if(mini != d[x][y]){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  vector<pair<P, int>> e1;
  vector<pair<P, char>> e2;
  rep(i, 100){
    e2.pb(mk(i + 1, i + 2), 'X');
  }
  rep(i, 100){
    e2.pb(mk(102 + i, 103 + i), 'Y');
  }
  rep(i, 101){
    rep(j, 101){
      e1.pb(mk(i + 1, 102 + j), f[i][100-j]);
    }
  }
  cout << 202 << " " << sz(e1) + sz(e2) << endl;
  rep(i, sz(e1)){
    cout << e1[i].first.first << " " << e1[i].first.second << " " << e1[i].second << endl;
  }
  rep(i, sz(e2)){
    cout << e2[i].first.first << " " << e2[i].first.second << " " << e2[i].second << endl;
  }
  cout << "1 202" << endl;
  return 0;
}
