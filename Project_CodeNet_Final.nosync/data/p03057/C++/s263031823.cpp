/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-03 17:07:09
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=2000010,mod=1000000007;
i64 n,m,flag,l,Flag;
i64 f[N],F[N],ans;
char s[N];
namespace std
{
	int main()
	{
		i64 i,j,t;
		for(i=1;i<=m;i++) if(s[i]!=s[1]) break;
		l=i-1;
		if(l%2==0) l++;
		for(t=0;i<=m;i++)
		{
			if(s[i]==s[1]) t++;
			else
			{
				if(t&1) l=min(l,t);
				t=0;
			}
		}
		n/=2,l=(l+1)/2;
		return 0;
	}
}
int main()
{
	n=read(); m=read();
	scanf("%s",s+1);
	fr(i,2,m) if(s[i]!=s[1]) flag=1;
	if(!flag)
	{
		f[0]=1; f[1]=1; f[2]=2;
		fr(i,3,n) f[i]=(f[i-1]+f[i-2])%mod;
		printf("%d\n",int((f[n]+f[n-2])%mod));
		return 0;
	}
	for(int i=1,j;i<=m;)
		if(s[i]==s[1])
		{
			j=i;
			while(s[j]==s[1]) j++;
			if(j>n) break;
			if(!Flag) l=j-i+((j-i)%2==0);
			else if((j-i)&1) l=std::min(l,(i64)(j-i));
			i=j+1; Flag=1;
		}
		else i++;
	if(n&1){ printf("0\n"); return 0; }
	std::main();
//	printf("%d %d\n",int(n),int(l));
	f[0]=F[0]=1;
	fr(i,1,n)
	{
		f[i]=(F[i-1]+mod-(i-l-1>=0?F[i-l-1]:0))%mod;
		F[i]=(F[i-1]+f[i])%mod;
//		printf("%d%c",int(f[i]),i==n?'\n':' ');
	}
	ans=f[n];
	fr(i,1,l) ans=(ans+f[n-i]*(2*i-1))%mod;
	printf("%d\n",int(ans));
	return 0;
}