bool DBG = false;
//#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using ld = long double;
//using i128 = __int128_t;
//using bint = boost::multiprecision::cpp_int;
//using d1024 = boost::multiprecision::number<mp::cpp_dec_float<1024>>;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=((b)-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
//#define ncouts(x) numout(x),outst[outst_N++] = ' '
//#define ncoutn(x) numout(x),outst[outst_N++] = '\n'
//#define scouts(x) strout(x),outst[outst_N++] = ' '
//#define scoutn(x) strout(x),outst[outst_N++] = '\n'
#define dcouts(x) if(DBG) couts(x)
#define dcoutn(x) if(DBG) coutn(x)
#define endl "\n"
#define psb push_back
#define ppb pop_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define LBIT(x,a) (((x)>>(a))&1LL)
#define IBIT(x,a) (((x)>>(a))&1)
#define BCOUNT(x) (__builtin_popcount(x))
#define sorta(x) sort(ALL(x))
#define sortra(x) sort(RALL(x))
#define revall(x) reverse(ALL(x))
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
/*
std::ostream &operator<<(std::ostream &os, const i128 nu){
  i128 co = nu;
  if(co==0){cout << '0';}
  else{
    string ous; if(co<0){cout<<'-'; co*=-1;}
    while(co){
      ous += (co%10)+'0';
      co /= 10;
    }
    reverse(ALL(ous));
    cout<<ous;
  }
  return os;
}
std::istream &operator>>(std::istream &is, i128 &nu){ string cs; cin >> cs; nu=0;int mn=1; for(auto &x:cs) { if(x!='-'){nu*=10;nu+=(x-'0');} else mn *= -1;} nu *= mn;  return is; }

*/


template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
template<class T> using V4 = V<V3<T>>;


constexpr ll LINF = 1LL << 60;
constexpr int IINF = 1 << 28;
constexpr ll mod =  1'000'000'007;
//constexpr ll mod = 998244353;

using PIL = pair<int,ll>;
using PLI = pair<ll,int>;
int n, m;
int s, t;
ll ans = 0;
V2<PIL> g;
V<set<int>> par;
V2<ll> dist, tori;
set<int> plist;
ll st_dist = 0;

void dk(int ss, int mode){
  priority_queue<PLI,V<PLI>,greater<PLI>> q;
  dist[mode][ss] = 0;
  tori[mode][ss] = 1;
  q.push(PLI(0,ss));
  
  while(!q.empty()){
    auto p = q.top(); q.pop();
    int v = p.sd;
    if(dist[mode][v]<p.fs) continue;
    for(auto e:g[v]){
      if(dist[mode][e.fs]==dist[mode][v]+e.sd){
        (tori[mode][e.fs] += tori[mode][v] ) %= mod;
        if(mode==0) { par[e.fs].insert(v);}
      }
      else if(dist[mode][e.fs]>dist[mode][v]+e.sd){
        dist[mode][e.fs] = dist[mode][v]+e.sd;
        tori[mode][e.fs] = tori[mode][v];
        if(mode==0) { par[e.fs] = set<int>(); par[e.fs].insert(v);}
        q.push(PLI(dist[mode][e.fs], e.fs) );
      }
    }
  }
}

void plist_ud(int ss){
  plist.insert(ss);
  if( dist[0][ss]*2==st_dist ) {ll z = (tori[0][ss]*tori[1][ss])%mod;(ans +=  mod-z*z%mod) %= mod;}
  for(auto x: par[ss]){
    if(dist[0][x]*2<st_dist && dist[0][ss]*2>st_dist ) {ll z = (tori[0][x]*tori[1][ss])%mod; (ans += mod - z*z%mod )%= mod;}
    if(dist[0][ss]*2<st_dist && dist[0][x]*2>st_dist ) {ll z = (tori[0][ss]*tori[1][x])%mod; (ans += mod - z*z%mod )%= mod;}
    if(plist.find(x)!=plist.end()) continue;
    plist_ud(x);
  }
  
}

void solve(){
  cin >> n >> m >> s >> t;
  --s, --t;
  g = V2<PIL>(n);
  dist = V2<ll>(2, V<ll>(n,LINF) );
  tori = V2<ll>(2, V<ll>(n,0) );
  par = V<set<int> >(n);
  FOR(_,0,m){
    int u, v; ll d; cin >> u >> v >> d;
    --u, --v;
    g[u].psb(PIL(v,d));
    g[v].psb(PIL(u,d));
  }
  
  dk(s,0);
  dk(t,1);
  if(dist[0][t]==LINF) {cout<<0;return;}
  
  ans = (tori[0][t]*tori[0][t]) % mod;// coutn(ans);
  st_dist = dist[0][t];
  plist_ud(t);
  
  /*
  for(auto x:plist){
    if( dist[0][x]*2==st_dist ) (ans +=  mod-(tori[0][x]*tori[1][x])%mod) %= mod;
  }*/
  
  
  //coutn(dist); coutn(par); coutn(tori);
  
  cout<<ans;
  
  
  
}



int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  //printf("%s", outst);
  return 0;
}

