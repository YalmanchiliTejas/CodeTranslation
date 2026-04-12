#include<bits/stdc++.h>
using namespace std;
typedef int sign;
typedef long long ll;
#define For(i,a,b) for(register sign i=(sign)(a);i<=(sign)(b);++i)
#define Fordown(i,a,b) for(register sign i=(sign)(a);i>=(sign)(b);--i)
const int N=3e3+5;
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
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
}
int n,mo;
void input()
{
	n=read<int>(),mo=read<int>();
}
int f[N][N];
ll power(ll x,int y,int Mod)
{
	ll res=1;
	for(;y;x=x*x%Mod,y>>=1)if(y&1)res=res*x%Mod;
	return res;
}
int g[N];
int mc[N],inv[N];
ll C(int x,int y){return 1ll*mc[x]*inv[y]%mo*inv[x-y]%mo;}
ll cal(int i)
{
	int res=0;
	int x=power(2,n-i,mo-1);
	x=power(2,x,mo);
	For(j,0,i)res=(res+1ll*power(2,(n-i)*j,mo)*f[i][j]%mo)%mo;
	return 1ll*x*res%mo;
}
void work()
{
	f[0][0]=1;
	For(i,1,n)
	{
		f[i][0]=1;
		For(j,1,i)f[i][j]=(f[i-1][j-1]+1ll*f[i-1][j]*(j+1)%mo)%mo;
	}
	mc[0]=inv[0]=1;
	For(i,1,n)mc[i]=1ll*mc[i-1]*i%mo;
	inv[n]=power(mc[n],mo-2,mo);
	Fordown(i,n-1,1)inv[i]=1ll*inv[i+1]*(i+1)%mo;
	int ans=0;
	For(i,0,n)
	{
		if(i&1)ans=(ans+mo-1ll*C(n,i)*cal(i)%mo)%mo;
		else ans=(ans+1ll*C(n,i)*cal(i)%mo)%mo;
	}
	write(ans,'\n');
}
int main()
{
//	file();
	input();
	work();
	return 0;
}