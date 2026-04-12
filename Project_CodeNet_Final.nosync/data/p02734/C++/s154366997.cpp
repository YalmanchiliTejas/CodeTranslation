#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e3+51,MOD=998244353;
ll n,s,res;
ll num[MAXN],dp[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
} 
int main()
{
	n=read(),s=read();
	for(register int i=1;i<=n;i++)
	{
		num[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=s;j>num[i];j--)
		{
			dp[j]=(dp[j]+dp[j-num[i]])%MOD;
		}
		dp[num[i]]=(dp[num[i]]+i)%MOD,res=(res+dp[s]*(n-i+1)%MOD)%MOD,dp[s]=0;
	}
	printf("%lld\n",res);
}