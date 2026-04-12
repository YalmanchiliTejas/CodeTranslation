#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

const ll MOD=1e9+7;
ll ad(ll x,ll y=0){
  return (x+y)%MOD;
}

int main(){
  string k;
  ll d,n,dp[10010][100]={},ans=0,s=0;
  cin>>k>>d;
  n=k.length();
  dp[0][0]=1;
  Fr(i,n) fr(j,d) for(int l=0;l<10;l++) dp[i][j]=ad(dp[i][j],dp[i-1][((j-l)%d+d)%d]);
  fr(i,n){
    for(int j=0;j<k[i]-'0';j++){
      ans=ad(ans,dp[n-1-i][(d-(s+j)%d)%d]);
    }
    s=(s+k[i]-'0')%d;
  }
  if(s==0) ans++;
  cout<<(ans+MOD-1)%MOD<<endl;
}