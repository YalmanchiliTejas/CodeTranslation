/////////////////////////////////////////////////////////
//
//  c/temp.cpp file
//  Last Updated: 2018-08-07 ...Maybe
//
//    I hope you adding this code to the setting file
//    alias g++='g++ -std=c++1y -DDEBUG_LOCAL'
//
/////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

//#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REAP(i,0,n)
#define REAP(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REAP,_REP,)(__VA_ARGS__)

#define _REPR(i,n) REAPR(i,n,0)
#define REAPR(i,a,b) for(int i=int(a-1);i>=int(b);--i)
#define REPR(...) _overload3(__VA_ARGS__,REAPR,_REPR,)(__VA_ARGS__)

#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()

#define coutALL(a) {int loop_coutALL=0;for(auto e:a) cout<<(loop_coutALL++?" ":"")<<e; cout<<endl;}

#define coutYN(a) cout<<((a)?"YES":"NO")<<endl;
#define coutYn(a) cout<<((a)?"Yes":"No")<<endl;
#define coutyn(a) cout<<((a)?"yes":"no")<<endl;

#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)

const int INF=1145141919;
const int MOD=(int)1e9+7;
const double EPS=1e-12;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;

typedef long long ll;

template<typename T> istream &operator >> (istream &is, vector<T> &v){for(T &x:v) is>>x;return is;}
template<typename T> ostream &operator << (ostream &os, vector<T> &v){int i=0;for(T &x:v) os<<(i++?" ":"")<<x;return os;}

ll rev(ll n){ll x=0;for(;n>0;){x=x*10+n%10;n/=10;}return x;}

template<class T> ll upper(T n,T m){return (n+m-1)/m;};
template<class T> ll rounding(T n){return (long double)n+0.5;};

template<class T> bool inG(T x,T n){return 0<=x && 0<n;}
template<class T> bool outG(T x,T n){return x<0 || n<=x;}

inline int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
inline int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

inline ll fac(ll k,ll n){ll a=1;for(int i=0;i<n;i++)a*=k--;return a;}
inline ll fac(ll k,ll n,int mo){ll a=1;for(int i=0;i<n;i++)a*=k--,a%=mo;return a;}

struct Arithmetic{Arithmetic(){cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);}};

//#define DEBUG_LOCAL

#ifdef DEBUG_LOCAL
template<typename T> void deb(T a){cerr<<"deb: "<<a<<"です"<<endl;}
#define debl {cerr<<"debug: "<<__LINE__<<"行目だ"<<endl;}
void what_cr(){cout<<__GCC_ATOMIC_CHAR16_T_LOCK_FREE<<" ←？"<<endl;}
//ori_func S

//ori_func E
#else
template<typename T>void deb(T a){}
#define debl
void what_cr(){}void t_t(){}
#endif

signed main(){

  Arithmetic Exception;

  int h,w;
  cin>>h>>w;

  string s[h];
  REP(i,h) cin>>s[i];

  int x[100]={},y[100]={};

  REP(i,h) y[i]= s[i].find('#')!=string::npos;
  REP(j,w) REP(i,h) x[j] |= s[i][j]=='#';

  REP(i,h){

    if(!y[i]) continue;

    REP(j,w) if(x[j]) cout<<s[i][j];

    cout<<endl;

  }

  return 0;

}
