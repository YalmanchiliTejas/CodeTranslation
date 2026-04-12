#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}

int main()
{
  int n;
  scanf("%d",&n);
  long long h[110],X[110];
  X[0]=0;
  for(int i=0;i<n;i++){
    scanf("%lld",h+i);
    X[i+1]=h[i];
  }
  sort(X,X+n+1);
  int r[110];
  for(int i=0;i<n;i++){
    r[i]=lower_bound(X,X+n+1,h[i])-X;
  }
  long long dp[110][110];
  for(int j=0;j<=r[0];j++){
    dp[0][j]=(j==0?1ll:2ll)*pw(2ll,X[r[0]]-X[j])%mod;
  }
  for(int i=1;i<n;i++){
    if(r[i-1]<=r[i]){
      for(int j=0;j<=r[i-1];j++){
	dp[i][j]=(dp[i-1][j]+dp[i-1][r[i-1]])%mod*pw(2ll,X[r[i]]-X[r[i-1]])%mod;
      }
      for(int j=r[i-1]+1;j<=r[i];j++){
	dp[i][j]=2ll*dp[i-1][r[i-1]]%mod*pw(2ll,X[r[i]]-X[j])%mod;
      }
    }
    else{
      for(int j=0;j<=r[i];j++){
	dp[i][j]=(dp[i-1][j]+dp[i-1][r[i]])%mod;
      }
    }
  }
  printf("%lld\n",dp[n-1][0]);
  return 0;
}

      
