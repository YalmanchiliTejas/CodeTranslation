#include<bits/stdc++.h>
using namespace std;
typedef int sign;
typedef long long ll;
#define For(i,a,b) for(register sign i=(sign)(a);i<=(sign)(b);++i)
#define Fordown(i,a,b) for(register sign i=(sign)(a);i>=(sign)(b);--i)
const int N=100+5;
template<typename T>bool cmax(T &a,T b){return (a<b)?a=b,1:0;}
template<typename T>bool cmin(T &a,T b){return (a>b)?a=b,1:0;}
template<typename T>T read()
{
	T ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch-'0'),ch=getchar();
	return ans*f;
}
template<typename T>void write(T x,char y)
{
	if(x==0)
	{
		putchar('0'),putchar(y);
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	static char wr[20];
	int top=0;
	for(;x;x/=10)wr[++top]=x%10+'0';
	while(top)putchar(wr[top--]);
	putchar(y);
}
void file()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
}
int n,h[N];
void input()
{
	n=read<int>();
	For(i,1,n)h[i]=read<int>();
}
int q[N],top;
void init()
{
	For(i,1,n)q[++top]=h[i];
	sort(q+1,q+top+1);
	top=unique(q+1,q+top+1)-q-1;
	For(i,1,n)h[i]=lower_bound(q+1,q+top+1,h[i])-q;
}
const int mo=1e9+7;
int dp[N][N];
ll power(ll x,int y)
{
	ll res=1;
	for(;y;x=x*x%mo,y>>=1)if(y&1)res=res*x%mo;
	return res;
}
void add(int &x,int y)
{
	x+=y;x-=(x>=mo?mo:0);
}
void work()
{
	dp[0][0]=1;	
	For(i,1,n)
	{
		add(dp[i][0],dp[i-1][0]*2%mo);
		For(j,h[i]+1,h[i-1])add(dp[i][0],dp[i-1][j]*2%mo);
		int d=(h[i]>h[i-1]?power(2,q[h[i]]-q[h[i-1]]):1);
		For(j,1,min(h[i-1],h[i]))dp[i][j]=1ll*dp[i-1][j]*d%mo;
		For(j,h[i-1]+1,h[i])
		{
			if(j>1)dp[i][j]=1ll*dp[i-1][0]*power(2,q[h[i]]-q[j])%mo*(power(2,q[j]-q[j-1])-1)%mo*2%mo;
			else dp[1][1]=1ll*(power(2,q[1])-2)*power(2,q[h[1]]-q[1])%mo;
		}
	}
	int ans=0;
	For(i,0,h[n])add(ans,dp[n][i]);
	write(ans,'\n');
}
int main()
{
//	file();
	input();
	init();
	work();
	return 0;
}
