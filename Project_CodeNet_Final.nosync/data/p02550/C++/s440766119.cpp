#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a) for (int i = 0; i < (int)(a); i++)
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
typedef long long ll;
template<typename T>istream& operator>>(istream&i,vector<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const vector<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template <typename Head> void dump(Head &&head) {
  cerr << head;
  dump();
}
template <typename Head, typename... Tail>
void dump(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  dump(forward<Tail>(tail)...);
}
#define debug(...)                                                               \
  do {                                                                         \
    cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = ";                        \
    dump(__VA_ARGS__);                                                         \
  } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template <typename T> struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

const ll LINF = 1LL << 60;
const int INF = 1001001001;

/////////////////////////////////////////////////////////////////////

int main()
{
  ll n; cin >> n;
  ll x; cin >> x;
  ll m; cin >> m;

  ll t = x;
  set<ll> st;
  vector<ll> a;
  a.push_back(t);
  st.insert(t);
  ll p = -1;
  for (ll i=0; i<=m; i++) {
    t = t*t % m;
    if (st.find(t) != st.end()) {
      p = t;
      break;
    }
    st.insert(t);
    a.push_back(t);
  }

  ll ans = 0;
  // debug(a);

  ll len = a.size();
  ll idx = -1;
  for (ll i=0; i<len; i++) {
    if (a[i] == p) break;
    if (i >= n) {
      cout << ans << "\n";
      return 0;
    };
    ans += a[i];
    idx = i;
  }
  idx++;
  // debug(ans);

  vector<ll> b;
  ll sum = 0;
  for (ll i=idx; i<len; i++) {
    b.push_back(a[i]);
    sum += a[i];
  }
  ll blen = b.size();
  n -= idx;
  // debug(b);
  // debug(sum);
  // debug(blen);
  // debug(n);

  if (blen == 0) {
    cout << ans << "\n";
    return 0;
  }

  ans += (n/blen)*sum;
  for (ll i=0; i<n%blen; i++) {
    ans += b[i];
  }
  cout << ans << "\n";

  return 0;
}
