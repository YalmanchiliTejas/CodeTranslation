#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
#define cinv(n,vec) VL (vec)(n);for(auto&v:vec)cin>>v;
#define int long long
#define itn int
#define pb push_back
#define m_p make_pair
#define m_t make_tuple
#define eb emplace_back
#define p_p(a,b) pb(m_p(a,b))
#define all(a) a.begin(),a.end()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(all(a),greater<>())
#define UNIQUE(a) a.erase(unique(all(a)),a.end())
#define SZ(a) (ll)(a.size())
#define ENDL cout<<endl
#define debg(a) cout<<#a<<" "<<a<<endl;
#define debgp(a) cout<<#a<<" "<<a.fi<<" : "<<a.se<<endl
#define call(a) for(auto i:a)cout<<i<<" ";cout<<endl
#define show(a) for(cont &y:a){for(cont &x:y){cout<<x<<" ";}cout<<endl;}
#define out(a) cout<<(a)<<endl
#define cont const auto
#define fi first
#define se second
#define V vector
#define P pair
#define T tuple
#define VV(type,name,y,x,a) vector<vector<type>> name = vector<vector<type>>(y,vector<type>(x,a))
#define PQ priority_queue
typedef long long ll;
typedef double D;
typedef long double LD;
typedef string str;
typedef vector<ll> VL;
typedef pair<ll,ll> PL;
typedef vector<pair<ll,ll>> VP;
typedef tuple<ll,ll,ll> T3;
typedef tuple<ll,ll,ll,ll> T4;
const long long INF = 1LL<<60;
const long long MOD = 1e9+7;
void Yes(){cout<<"Yes"<<endl;}
void No(){cout<<"No"<<endl;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int h,w;
  cin>>h>>w;
  V<str> a(h);
  rep(i,h)cin>>a[i];

  int cnt=0;
  rep(i,h)rep(j,w)cnt+=(a[i][j]=='#');
  out(cnt==h+w-1?"Possible":"Impossible");
  
  return 0;
}

