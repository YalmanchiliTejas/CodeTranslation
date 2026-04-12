#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f,N=1e7+4,mod=998244353;
int n,inv[N],fac[N],fic[N],bin[N],bi[N];
int C(int x,int y)
{if(y>x)return 0;if(0==y)return 1;//cout<<x<<" "<<y<<" "<<fac[x]*fic[y]%mod*fic[x-y]%mod<<endl;
	return fac[x]*fic[y]%mod*fic[x-y]%mod;
}
main()
{inv[1]=fac[1]=fic[1]=1;bin[0]=bi[0]=fic[0]=1;
for(int i=2;i<=1e7;i++)inv[i]=mod-inv[mod%i]*(mod/i)%mod,fac[i]=fac[i-1]*i%mod,fic[i]=fic[i-1]*inv[i]%mod;
//for(int i=1;i<=3;i++)cout<<inv[i]<<" "<<fic[i]<<endl;
for(int i=1;i<=1e7;i++)bi[i]=bi[i-1]*3%mod,bin[i]=(bin[i-1]*2%mod);
	cin>>n;int ans=bi[n];//cout<<ans<<endl;
	for(int i=n/2+1;i<=n;i++)
	{
		int ret=C(n,i)*bin[n-i+1]%mod;ans=(ans-ret)%mod;
		//cout<<ans<<endl;
	}cout<<(ans+mod)%mod;
	return 0;
}
