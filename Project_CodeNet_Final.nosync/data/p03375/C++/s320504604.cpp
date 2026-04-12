#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow_mod(ll x,int k,int mod) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%mod;
  	x=x*x%mod;
  	k>>=1;
  }
  return ans;
}

int MOD;

ll C[3005][3005],strl[3005][3005];

void pre(int n) {
  for(int i=0;i<=n;i++) C[i][0]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
  strl[0][0]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) strl[i][j]=(strl[i-1][j-1]+strl[i-1][j]*j)%MOD;
}

int main() {
  int n;
  scanf("%d%d",&n,&MOD);
  pre(n+1);
  ll ans=0;
  for(int i=0;i<=n;i++) {
  	ll s=0,v=1,t=pow_mod(2,n-i,MOD);
  	for(int j=0;j<=i;j++) {
  		s=(s+v*strl[i+1][j+1])%MOD;
  		v=v*t%MOD;
	  }
	ans=(ans+C[n][i]*pow_mod(2,pow_mod(2,n-i,MOD-1),MOD)%MOD*((i&1)?MOD-1:1)%MOD*s)%MOD;
  }
  printf("%lld\n",ans);
  return 0;
}