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
#define F first
#define S second
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
using ll = unsigned long long int;
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

// status
// 0: and 1 -> all 1
// 1: and 0
// 2: or 1
// 3: or 0 -> all 0

// matrix
// 0: and 0, and 0
// 1: and 0, or 1
// 2: or 1, and 0
// 3: or 1, or 1
ll val[4][4];
ll res[510][510];

int get(ll x, int b){
  return (x >> b) & 1;
}

ll tmp[510][510];

int status(int s, int u){
  if(s == 0 && u == 1)return 0;
  if(s == 0 && u == 0)return 1;
  if(s == 1 && u == 1)return 2;
  return 3;
}

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<int> s(n), t(n); cin >> s >> t;
  vector<ll> u(n), v(n); cin >> u >> v;
  rep(b, 64){
    rep(i, n){
      rep(j, n)tmp[i][j] = 0;
    }
    rep(i, n){
      int row = status(s[i], (u[i] >> b) & 1);
      if(row == 0){
        rep(j, n)tmp[i][j] = 1;
      }
    }
    rep(i, n){
      int col = status(t[i], (v[i] >> b) & 1);
      if(col == 0){
        rep(j, n){
          tmp[j][i] = 1;
        }
      }else if(col == 3){
        rep(j, n){
          tmp[j][i] = 0;
        }
      }
    }
    vector<int> cntc(n, 0), cntr(n, 0);
    vector<int> or1c, or1r;
    rep(i, n){
      rep(j, n)cntr[i] += 1 - tmp[i][j];
      if(status(s[i], (u[i] >> b) & 1) == 2)or1r.pb(i);
    }
    rep(i, n){
      rep(j, n)cntc[i] += 1 - tmp[j][i];
      if(status(t[i], (v[i] >> b) & 1) == 2)or1c.pb(i);
    }
    rep(i, n){
      if(status(s[i], (u[i] >> b) & 1) == 2 && cntr[i] == n){
        if(sz(or1c)){
          tmp[i][or1c.back()] = 1;
          if(sz(or1c) > 1)or1c.pop_back();
        }else{
          rep(j, n){
            int r = status(t[j], v[j] >> b & 1);
            if((r == 1 || r == 2) && cntc[j] > 1){
              cntc[j]--;
              tmp[i][j] = 1;
              break;
            }
          }
        }
      }
    }
    cntc.assign(n, 0); cntr.assign(n, 0);
    or1c.clear(); or1r.clear();
    rep(i, n){
      rep(j, n)cntr[i] += 1 - tmp[i][j];
      if(status(s[i], (u[i] >> b) & 1) == 2)or1r.pb(i);
    }
    rep(i, n){
      rep(j, n)cntc[i] += 1 - tmp[j][i];
      if(status(t[i], (v[i] >> b) & 1) == 2)or1c.pb(i);
    }
    rep(i, n){
      if(status(t[i], (v[i] >> b) & 1) == 2 && cntc[i] == n){
        if(sz(or1r)){
          tmp[or1r.back()][i] = 1;
          if(sz(or1r) > 1)or1r.pop_back();
        }else{
          rep(j, n){
            int r = status(s[j], u[j] >> b & 1);
            if((r == 1 || r == 2) && cntr[j] > 1){
              cntr[j]--;
              tmp[j][i] = 1;
              break;
            }
          }
        }
      }
    }
    rep(i, n){
      rep(j, n){
        res[i][j] |= (1LL << b) * tmp[i][j];
      }
    }
    bool nok = true;
    rep(i, n){
      int cnt = 0;
      rep(j, n)cnt += tmp[i][j];
      int r = status(s[i], u[i] >> b & 1);
      if(r == 0 && cnt != n)nok = false;
      if(r == 1 && cnt == n)nok = false;
      if(r == 2 && cnt == 0)nok = false;
      if(r == 3 && cnt > 0)nok = false;
    }
    rep(i, n){
      int cnt = 0;
      rep(j, n)cnt += tmp[j][i];
      int r = status(t[i], v[i] >> b & 1);
      if(r == 0 && cnt != n)nok = false;
      if(r == 1 && cnt == n)nok = false;
      if(r == 2 && cnt == 0)nok = false;
      if(r == 3 && cnt > 0)nok = false;
    }
    /*
    if(!nok){
      cerr << s << endl;
      cerr << t << endl;
      rep(i, n){
        cerr << (u[i] >> b & 1) << " ";
      }
      cerr << endl;
      rep(i, n){
        cerr << (v[i] >> b & 1) << " ";
      }
      cerr << endl;
      cerr << "----- tmp -----" << endl;
      rep(i, n){
        rep(j, n){
          cerr << tmp[i][j] << " ";
        }
        cerr << endl;
      }
      cerr << "----- tmp -----" << endl;
    }
    */
  }
  bool ok = true;
  rep(i, n){
    ll andx = res[i][0], orx = res[i][0];
    FOR(j, 1, n){
      andx &= res[i][j];
      orx |= res[i][j];
    }
    if(s[i] == 1 && orx != u[i])ok = false;
    if(s[i] == 0 && andx != u[i])ok = false;
  }
  rep(i, n){
    ll andx = res[0][i], orx = res[0][i];
    FOR(j, 1, n){
      andx &= res[j][i];
      orx |= res[j][i];
    }
    if(t[i] == 1 && orx != v[i])ok = false;
    if(t[i] == 0 && andx != v[i])ok = false;
  }
  if(!ok){
    cout << -1 << endl;
    return 0;
  }
  rep(i, n){
    rep(j, n){
      cout << res[i][j];
      if(j + 1 == n)cout << endl;
      else cout << " ";
    }
  }
  return 0;
}
