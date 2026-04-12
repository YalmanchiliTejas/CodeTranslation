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
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> void chmin(T& t, const U& u){if(t>u)t=u;}
template<typename T,typename U> void chmax(T& t, const U& u){if(t<u)t=u;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}
ll n;
vector<ll> v;
ll dp[3000][3000]={};

ll dfs(int l,int r,int p){
   if(l==r)return v[l]*mpow(-1,p);

   ll a,b;
   if(dp[l+1][r]>=LINF){
      a=dfs(l+1,r,p^1);
      dp[l+1][r]=a;
   }else{
      a=dp[l+1][r];
   }

   if(dp[l][r-1]>=LINF){
      b=dfs(l,r-1,p^1);
      dp[l][r-1]=b;
   }else{
      b=dp[l][r-1];
   }

   if(!p){
      return max(a+v[l],b+v[r]);
   }else{
      return min(a-v[l],b-v[r]);
   }
}



signed main(){
   cin.tie(0);ios::sync_with_stdio(false);
   cout<<fixed<<setprecision(20);
   cin>>n;
   v.assign(n,0);
   rep(i,0,3000)rep(j,0,3000){
      dp[i][j]=LINF;
   }
   rep(i,0,n){
      cin>>v[i];
      dp[i][i]=v[i]*mpow(-1ll,n+1);
   }

   cout<<dfs(0,n-1,0)<<endl;

}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?