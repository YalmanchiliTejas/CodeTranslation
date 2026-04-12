#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
const int mod = 1e9+7;
int n,h[110],cnt,b[110];
ll f[110][110];
ll fp(ll a,ll k){
	ll ans=1;
	for(;k;k>>=1,a=a*a%mod)
		if(k&1) ans=a*ans%mod;
	return ans;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(h[i]),b[++cnt]=h[i];
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	for(int i=1;i<=n;i++)
		h[i]=lower_bound(b+1,b+cnt+1,h[i])-b;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]*2%mod;
		for(int j=h[i]+1;j<=h[i-1];j++) f[i][0]=(f[i][0]+f[i-1][j]*2)%mod;
		for(int j=1;j<=h[i];j++)
			if(h[i]>=h[i-1]) f[i][j]=f[i-1][j]*fp(2,b[h[i]]-b[h[i-1]])%mod;
			else f[i][j]=f[i-1][j];
		for(int j=h[i-1]+1;j<=h[i];j++)
			if(j>1) f[i][j]=f[i-1][0]*(fp(2,b[j]-b[j-1]+1)-2)%mod*fp(2,b[h[i]]-b[j])%mod;
			else f[i][j]=f[i-1][0]*(fp(2,b[j])-2)%mod*fp(2,b[h[i]]-b[j])%mod;
	}
	ll ans=0;
	for(int i=0;i<=h[n];i++)
		ans=(ans+f[n][i])%mod;
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}
