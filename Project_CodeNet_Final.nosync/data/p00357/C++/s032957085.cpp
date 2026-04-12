#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
/// {{{ DEBUG --- ///
#ifdef DEBUG
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << "{"; for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? ", " : ""); o << "}"; return o; }
#ifdef USE_COUT
#define dump(...) [&](){auto __debug_tap=make_tuple(__VA_ARGS__);cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<__debug_tap<<"\n";}()
#else
#define dump(...) [&](){auto __debug_tap=make_tuple(__VA_ARGS__);cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<__debug_tap<<"\n";}()
#endif
template<class T> inline void dump2D(T &d, size_t sizey, size_t sizex) { ostream&o=
#ifdef USE_COUT
  cout;
#else
  cerr;
#endif
  for(size_t i = 0; i < sizey; i++) { for(size_t j = 0; j < sizex; j++) o << d[i][j] << " "; o << endl; }
}
#else
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? " " : ""); return o; }
#define dump(...) (42)
#define dump2D(...) (42)
#endif
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
/// }}}--- ///


int sol() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &e:v)cin >> e, e/=10;
  int cango = 0;
  int now = 0;
  while(now < n && now <= cango) {
    cango = max(cango, now + v[now]);
    now++;
  }
  // dump(
  if(cango < n - 1) return 0;
  now = n -1;
  cango = n-1;
  while(now >= 0 && now >= cango) {
    cango = min(cango, now - v[now]);
    now--;
  }
  if(cango > 0) return 0;
  return 1;
}

#define POS(x) cout<<((x)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define Pos(x) cout<<((x)?"Possible":"Impossible")<<endl;
#define YES(x) cout<<((x)?"YES":"NO")<<endl;
#define Yes(x) cout<<((x)?"Yes":"No")<<endl;
#define yes(x) cout<<((x)?"yes":"no")<<endl;

int main() {
  yes(sol());
}


