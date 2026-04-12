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
const int MAXN=8005;
const int MAXM=205;
const int mod=998244353;
int pow_mod(int a,int b)
{
	int ret=1;
	for(;b;b>>=1,a=1LL*a*a%mod)if(b&1)ret=1LL*ret*a%mod;
	return ret;
}
vector<int> wn[2][25];
void init()
{
	for(int i=1,t=0;i<MAXN*4;i<<=1,++t)
	{
		int w1=pow_mod(3,(mod-1)/(i<<1)),w2=pow_mod(w1,mod-2);
		for(int j=0,u=1,v=1;j<i;j++,u=1LL*u*w1%mod,v=1LL*v*w2%mod)
			wn[0][t].emplace_back(u),wn[1][t].emplace_back(v);
	}
}
int R[MAXN*4],L;
void NTT(int *y,int len,int on)
{
	for(int i=0;i<len;i++)if(i<R[i])swap(y[i],y[R[i]]);int g=(on==-1?1:0);
	for(int i=1,t=0;i<len;i<<=1,++t)for(int j=0;j<len;j+=(i<<1))for(int k=0;k<i;k++)
	{
		int u=y[j+k],v=1LL*y[j+k+i]*wn[g][t][k]%mod;
		y[j+k]=(u+v)%mod;y[j+k+i]=(u-v+mod)%mod;
	}if(on==-1)for(int i=0,temp=pow_mod(len,mod-2);i<len;i++)y[i]=1LL*y[i]*temp%mod;
}
int pre[MAXN],inv[MAXN];
int C(int n,int m){return n<m?0:1LL*pre[n]*inv[m]%mod*inv[n-m]%mod;}
int n,m,f[MAXM][MAXN*4],A[MAXN*4],B[MAXN*4];
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
int main()
{
	pre[0]=1;for(int i=1;i<MAXN;i++)pre[i]=1LL*pre[i-1]*i%mod;
	inv[MAXN-1]=pow_mod(pre[MAXN-1],mod-2);
	for(int i=MAXN-2;i>=0;i--)inv[i]=1LL*inv[i+1]*(i+1)%mod;
	init();n=read();m=read();
	for(int i=0;i<=n;i++)f[m][i]=C(n,i);
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			ad(f[i][j],1LL*f[i+1][j]*C(j+1,2)%mod);ad(f[i][j],f[i+1][j]);
//			for(int k=j+1;k<=n;k++)ad(f[i][j],1LL*f[i+1][k]*C(k+2,k+2-j)%mod);
		}
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		for(int j=0;j<=n;j++)B[j+2]=1LL*f[i+1][j]*pre[j+2]%mod;
		for(int j=3;j<=n+2;j++)A[j]=inv[j];reverse(A,A+1+(n+2));int ln;L=0;
		for(ln=1;ln<=2*(n+2);ln<<=1)++L;
		for(int j=0;j<ln;j++)R[j]=(R[j>>1]>>1)|(j&1)<<(L-1);
		NTT(B,ln,1);NTT(A,ln,1);
		for(int j=0;j<ln;j++)A[j]=1LL*A[j]*B[j]%mod;NTT(A,ln,-1);
		for(int j=0;j<=n;j++)ad(f[i][j],1LL*A[j+n+2]*inv[j]%mod);
	}
	pr2(f[0][0]);
	return 0;
}
