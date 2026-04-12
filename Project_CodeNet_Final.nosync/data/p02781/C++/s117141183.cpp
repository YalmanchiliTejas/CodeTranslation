#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=151;
string x;
ll kk,l;
ll dp[MAXN][4][2];
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
inline ll dfs(ll l,ll cur,ll x)
{
	ll p,res=0;
	if(cur>kk)
	{
		return 0;
	}
	if(l>=::l)
	{
		return cur==kk;
	}
	if(dp[l][cur][x]!=-1)
	{
		return dp[l][cur][x];
	}
	p=x==1?::x[l]-'0':9;
	for(register int i=0;i<=p;i++)
	{
		res+=dfs(l+1,cur+!!i,x&&i==p);
	}
	return dp[l][cur][x]=res;
}
int main()
{
	cin>>x,kk=read(),l=x.length(),memset(dp,-1,sizeof(dp));
	printf("%lld\n",dfs(0,0,1));
}