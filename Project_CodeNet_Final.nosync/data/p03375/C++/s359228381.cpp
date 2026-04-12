#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3010;
int n,mod,s[N][N],c[N][N],ans=0;
int poww(int x,int y,int mo){
	int ans=1;
	while(y){
		if(y&1){
			ans=ans*x%mo;
		}
		x=x*x%mo;
		y>>=1;
	}
	return ans;
}
signed main(){
	scanf("%lld%lld",&n,&mod);
	s[0][0]=1;
	for(int i=0;i<=n+1;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for(int i=0;i<=n;i++){
		int sum=0;
		for(int j=0;j<=i;j++){
			(sum+=s[i+1][j+1]*poww(2,j*(n-i),mod)%mod)%=mod;
		}
		sum=sum*poww(2,poww(2,n-i,mod-1),mod)%mod*c[n][i]%mod;
		(ans+=(i&1)?mod-sum:sum)%=mod;
	}
	printf("%lld",ans);
}