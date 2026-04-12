//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
constexpr ll mod = 998244353;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 +99);
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

ll dp[3010][3010]={};
ll sum[3010][3010]={};


signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,s,ans=0;cin>>n>>s;
  V<ll> v(n);
  rep(i,0,n)cin>>v[i];
  dp[0][0]=1;

  rep(i,1,n+1){
    rep(j,0,3010){
      dp[i][j]=dp[i-1][j];
      dp[i][j]%=mod;

      sum[i][j]+=sum[i-1][j];
      sum[i][j]%=mod;

      if(j-v[i-1]>=0){
        dp[i][j]+=dp[i-1][j-v[i-1]];
        dp[i][j]%=mod;

        sum[i][j]+=sum[i-1][j-v[i-1]];    
        if(j==v[i-1])sum[i][j]+=i;
        sum[i][j]%=mod;
      }
    }

    ans+=sum[i][s]%mod;
    //cerr<<ans<<ENDL;
    ans%=mod;
  }

  cout<<ans<<ENDL;
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?