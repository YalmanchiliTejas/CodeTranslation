#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=105;
const int mod=1e9+7;
int pow_mod(int a,int b)
{
	int ret=1;
	for(;b;b>>=1,a=1LL*a*a%mod)if(b&1)ret=1LL*ret*a%mod;
	return ret;
}
int f[MAXN][MAXN],g[MAXN][MAXN],h[MAXN],a[MAXN],n;
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
//f same 
//g not same
void dp(int l,int r,int down)
{
	if(l>r)return ;
	if(l==r){g[l][r]=pow_mod(2,h[l]-down);return ;}
	int mn=0;for(int i=l;i<=r;i++)if(!mn||h[i]<h[mn])mn=i;
	int s1=0,s2=0;
	for(int i=l,nxt;i<=r;i=nxt+1)
	{
		nxt=i;
		if(h[i]==h[mn])
		{
			s1=2LL*s1%mod;ad(s1,2LL*s2%mod);
			if(!s2)s2=1;continue;
		}while(h[nxt+1]>h[mn]&&nxt+1<=r)++nxt;
		dp(i,nxt,h[mn]+1);
		int u1=f[i][nxt],u2=g[i][nxt];
		if(i!=l)
		{
			if(!s1)
			{
				ad(s1,2LL*s2*u1%mod);
				ad(s1,4LL*u2*s2%mod);
			}
			else 
			{
				s1=(4LL*s1*u2%mod+1LL*s1*u1%mod)%mod;ad(s1,2LL*s2*u1%mod);
				ad(s1,4LL*u2*s2%mod);
			}
			if(!s2)s2=2LL*u2%mod;
			else s2=2LL*s2*u2%mod;
		}
		else s1=u1,s2=2LL*u2%mod;
	}
	if(h[mn]>down)s2=1LL*s2*pow_mod(2,h[mn]-down)%mod;
	f[l][r]=s1;g[l][r]=s2;
}
int main()
{
	n=read();for(int i=1;i<=n;i++)h[i]=a[i]=read();
	if(n==1)return pr2(pow_mod(2,h[1])),0;
	sort(a+1,a+1+n);int ln=unique(a+1,a+1+n)-(a+1);
	a[0]=1;
	dp(1,n,1);
	pr2((f[1][n]+2LL*g[1][n])%mod);
	return 0;
}
