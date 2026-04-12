#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define rep(i,N) For(i,0,N)
#define endl "\n"
#define print(v) cout<<v<<endl
const ll inf=1LL<<60;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
ll N;
vec v;
mat dp;
ll solve(ll now,ll path,ll cnt){
  if(now>=N)return (cnt!=N/2)*-inf;
  if(path>(N&1)+1)return -inf;
  if(dp[now][path]!=-inf)return dp[now][path];
  ll i,res=-inf;
  rep(i,2+(N&1))chmax(res,solve(now+i+2,path+i,cnt+1));
  return dp[now][path]=res+v[now];
}
int main(){
  ll i,ans=-inf;
  cin>>N;
  v.resize(N);
  dp.resize(N,vec(3,-inf));
  rep(i,N)cin>>v[i];
  rep(i,2+(N&1))chmax(ans,solve(i,i,0));
  print(ans);
}