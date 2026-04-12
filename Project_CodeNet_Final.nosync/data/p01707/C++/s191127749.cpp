#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll dp[2002][2002];
ll n,d,x;

ll mod_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1LL)res=res*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return res;
}

int main(void){
	while(1){
		scanf("%lld %lld %lld",&n,&d,&x);
		if(n+d+x==0LL)break;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=n;j++){
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j-1])%MOD;
				if(j>=x)dp[i+1][j]=(dp[i+1][j]+MOD-dp[i][j-x])%MOD;
			}
		}
		ll res=0;
		for(ll i=1;i<=min(n,d);i++){
			ll cnt=1;
			for(ll j=0;j<i;j++){
				ll g=(d-j)%MOD;
				g=g*mod_pow(i-j,MOD-2LL)%MOD;
				cnt=cnt*g%MOD;
			}
			res=(res+cnt*dp[i][n])%MOD;
		}
		printf("%lld\n",res);
	}
	return 0;
}