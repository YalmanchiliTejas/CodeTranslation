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
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define lb lower_bound
#define ub upper_bound
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T> inline T mpow(T a, T n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

ll dp[10010][110][2]={};

signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  string k;cin>>k;
  ll d;cin>>d;

  dp[0][0][0]=1;
  rep(i,0,siz(k)){
    rep(j,0,d){
      rep(l,0,10){
        if(l+'0'<k[i]){
          (dp[i+1][(j+l)%d][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
        }else if(k[i]<l+'0'){
          (dp[i+1][(j+l)%d][1]+=dp[i][j][1])%=mod;
        }else{
          (dp[i+1][(j+l)%d][0]+=dp[i][j][0])%=mod;
          (dp[i+1][(j+l)%d][1]+=dp[i][j][1])%=mod;
        }
      }
    }
  }
  cout<<(dp[siz(k)][0][0]+dp[siz(k)][0][1]+mod-1)%mod<<ENDL;//except zero
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?