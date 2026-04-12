#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=100010;
const int inf=2147483647;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
bool u[Maxn];
LL n,x,m,a[Maxn];
int main()
{
	n=read(),x=read(),m=read();
	u[x]=true;
	a[1]=x;LL ans=x,t=x;
	for(LL i=2;i<=n;i++)
	{
		t=t*t%m;
		if(u[t])
		{
//			printf("%lld %lld %lld\n",i,t,ans);
			LL s=0;LL len;int p;
			for(int j=1;j<i;j++)
			if(a[j]==t)
			{
				len=i-j;p=j;
				for(int k=j;k<i;k++)s+=a[k];
				break;
			}
//			printf("%lld\n",s);
			ans+=(n-i+1)/len*s;
			for(LL j=1;j<=(n-i+1)%len;j++)
			ans+=a[p+j-1];
			break;
		}
		else
		{
			u[t]=true;ans+=t;
			a[i]=t;
		}
		
	}
	printf("%lld",ans); 
}