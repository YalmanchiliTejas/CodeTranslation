#include<bits/stdc++.h>
using namespace std;

const int N=3010;
typedef long long ll;
int mod,n,jc[N],jc2[N],inv[N],pww[N],pw[N*N],dp[N][N],ans;
int ksm(ll a,int b,int c=1){
	for(;b;b/=2,a=a*a%mod)
		if(b&1)c=c*a%mod;
	return c;
}
void init(){
	jc[0]=jc2[0]=pww[0]=1;
	for(int i=1;i<=n;++i){
		jc[i]=(ll)jc[i-1]*i%mod;
		inv[i]=ksm(i,mod-2);
		jc2[i]=(ll)jc2[i-1]*inv[i]%mod;
		pww[i]=pww[i-1]*2%(mod-1);
	}
	pw[0]=1;
	for(int i=1;i<=n*n;++i)pw[i]=pw[i-1]*2%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>mod;init();
	for(int j=0;j<=n;++j)dp[0][j]=jc2[j];
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			dp[i][j]=((ll)(dp[i][j-1]+dp[i-1][j-1])*i+dp[i][j-1])%mod*inv[j]%mod;
	for(int i=0;i<=n;++i){
		int sum=0;
		for(int j=0;j<=i;++j)
			sum=(sum+(ll)dp[j][i]*pw[j*(n-i)]%mod*jc2[j])%mod;
		sum=ksm(2,pww[n-i],sum);sum=(ll)sum*jc[n]%mod*jc2[n-i]%mod;
		if(i&1)ans=(ans-sum+mod)%mod;
		else ans=(ans+sum)%mod;		
	}
	cout<<ans<<'\n';
	return 0;
}
