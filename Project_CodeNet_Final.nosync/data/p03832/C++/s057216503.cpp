#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[1024][1024];
ll comb[1024][1024];
ll dv[1024];

ll modpow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)	ret=ret*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return ret;
}

int main(){
	ll n,a,b,c,d;	cin>>n>>a>>b>>c>>d;

	comb[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			comb[i+1][j]+=comb[i][j];
			comb[i+1][j]%=mod;
			comb[i+1][j+1]+=comb[i][j];
			comb[i+1][j+1]%=mod;
		}
	}
	dv[1]=1;
	for(int i=2;i<=n;i++)	dv[i]=modpow(i,mod-2);
	
	dp[a-1][n]=1;
	for(int i=a;i<=b;i++){
		for(int j=0;j<=n;j++){
			if(dp[i-1][j]==0)	continue;
			dp[i][j]+=dp[i-1][j];	dp[i][j]%=mod;
			if(j-i*c<0)	continue;
			ll multi=1;
			for(int k=1;k<c;k++){
				multi=(multi*comb[j-i*(k-1)][i])%mod;
				multi=(multi*dv[k])%mod;
			}
			for(int k=c;k<=d;k++){
				if(j-k*i<0)	break;
				multi=(multi*comb[j-i*(k-1)][i])%mod;
				multi=(multi*dv[k])%mod;
				dp[i][j-k*i]+=(multi*dp[i-1][j])%mod;
				dp[i][j-k*i]%=mod;
			}
		}
	}
	cout<<dp[b][0]<<endl;
	return 0;
}
