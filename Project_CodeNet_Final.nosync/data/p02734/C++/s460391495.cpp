#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define re register
#define ll long long
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=3010,Mod=998244353;
int n,S,a[N],f[N];
int main()
{
	n=gi();S=gi();
	for(int i=1;i<=n;i++)a[i]=gi();
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=S;j>a[i];j--)
		{
			f[j]=(f[j]+f[j-a[i]])%Mod;
		}
		f[a[i]]=(f[a[i]]+i)%Mod;
		ans=(ans+1ll*f[S]*(n-i+1)%Mod)%Mod;
		f[S]=0;
	}
	printf("%lld\n",ans);
	return 0;
}
