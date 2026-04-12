#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
ll b[60];
ll p[60];
ll sum[60];
ll f(ll n,ll x){
  if(n==0)return x>0;
  if(x==1)return 0;
  if(x>1&&x<=sum[n-1]+1)return f(n-1,x-1);
  if(x==sum[n-1]+2)return p[n-1]+1;
  if(x>sum[n-1]+2&&x<=sum[n-1]*2+2)return p[n-1]+1+f(n-1,x-2-sum[n-1]);
  if(x>=sum[n])return p[n];
  
}

int main(){
  ll n,x;
  cin>>n>>x;
  b[0]=0;
  p[0]=1;
  sum[0]=1;
  rep1(i,n){
    b[i]=b[i-1]*2+2;
    p[i]=p[i-1]*2+1;
    sum[i]=sum[i-1]*2+3;
  }
  ll ans=0;
  ans=f(n,x);
  cout<<ans<<endl;
  return 0;
}
