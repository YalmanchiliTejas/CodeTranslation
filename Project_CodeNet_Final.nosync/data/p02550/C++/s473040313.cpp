//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
constexpr ll mod = 1000000007; // 998244353;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 +99);
const ld PI = acos((ld)-1);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}

template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

template <typename T> V<T> prefix_sum(const V<T>& v) {
  int n = v.size();
  V<T> ret(n + 1);
  rep(i, 0, n) ret[i + 1] = ret[i] + v[i];
  return ret;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
  for(auto&& x: vec) is >> x;
  return is;
}

template<typename T,typename Y>
ostream& operator<<(ostream& os,const pair<T,Y>& p){
  return os<<"{"<<p.fs<<","<<p.sc<<"}";
}

template<typename T> ostream& operator<<(ostream& os,const V<T>& v){
  os<<"{";
  for(auto e:v)os<<e<<",";
  return os<<"}";
}

template<typename ...Args>
void debug(Args&... args){
  for(auto const& x:{args...}){
    cerr<<x<<' ';
  }
  cerr<<ENDL;
}



signed main(){
  cin.tie(0);cerr.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,x,m;cin>>n>>x>>m;

  map<ll,ll> ma;
  V<ll> v(1,0);

  ll t,now=1,pro=x;
  rep(i,1,n+1){
    now*=pro;
    now%=m;
    pro=now;

    if(ma.count(now)){
      t=i-ma[now];
      ll st=ma[now];
      ll ans=v[st-1];
      
      ans+=(v.back()-v[st-1])*((n-st+1)/t)+v[(n-st+1)%t+st-1]-v[st-1];

      cout<<ans<<ENDL;
      return 0;
    }

    v.eb(now);
    v.back()+=v[siz(v)-2];

    ma[now]=i;
  }
  cout<<v.back()<<ENDL;
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?