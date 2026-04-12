//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<cctype>
#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<set>
#include<map>
#define INF 1000000000
#define ll long long
#define mod 10007
#define pb push_back
using namespace std;
char *fs,*ft,buf[1<<15];
inline char getc()
{
	return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const ll MAXN=110;
char a[MAXN];
ll f[MAXN][4];//f[i][j]表示到了第i位此时出现了非0数位的方案数
ll n,k;
ll c[MAXN];
inline ll dfs(ll x,ll w,ll limit,ll s)//表示到了第x位出现了w位非0
//是否有最高位的限制是否存在前导0
{
	if(w<0)return 0;
	if(!limit&&f[x][w]!=-1)return f[x][w];
	if(!x)
	{
		if(!w)return f[x][w]=1;
		return f[x][w]=0;
	}
	ll maxx=limit?c[x]:9;
	ll cnt=0;
	for(ll i=0;i<=maxx;++i)
	{
		if(s&&i==0){cnt+=dfs(x-1,w,0,s);continue;}
		if(i==0)cnt+=dfs(x-1,w,limit&&i==maxx,0);
		else cnt+=dfs(x-1,w-1,limit&&i==maxx,0);
	}
	if(!limit&&!s)f[x][w]=cnt;
	return cnt;
}
int main()
{
	//freopen("1.in","r",stdin);
	memset(f,-1,sizeof(f));
	scanf("%s",a+1);
	n=strlen(a+1);k=read();
	for(ll i=1;i<=n;++i)c[i]=a[i]-'0';
	reverse(c+1,c+1+n);
	printf("%lld\n",dfs(n,k,1,1));
	return 0;
}
