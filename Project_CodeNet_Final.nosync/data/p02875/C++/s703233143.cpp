#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,N=10000010;
int n,jc[N],inv[N],ans,sum[N];

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int C(int a,int b)
{
	if (a<b||b<0) return 0;
	return 1ll*jc[a]*inv[b]%mod*inv[a-b]%mod;
}

int main()
{
	jc[0]=1;
	for (int i=1; i<N; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[N-1]=quickmi(jc[N-1],mod-2);
	for (int i=N-1; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%d",&n),ans=quickmi(3,n),sum[n>>1]=1;
	for (int i=(n>>1)-1,nw=2; i; i--,nw=(nw+nw>=mod?nw+nw-mod:nw+nw)) 
		sum[i]=(sum[i+1]+1ll*nw*C(n>>1,i))%mod;
	for (int i=(n>>1),nw=1; i; i--,nw=(nw+nw>=mod?nw+nw-mod:nw+nw))
		ans=(ans+2ll*(mod-nw)*C(n>>1,i)%mod*sum[(n>>1)+1-i])%mod;
	printf("%d\n",ans);
	return 0;
}