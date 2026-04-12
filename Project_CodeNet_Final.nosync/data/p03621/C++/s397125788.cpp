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
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
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
const int mod=998244353;
const int MAXN=10005;
int pow_mod(int a,int b)
{
	int ret=1;
	for(;b;b>>=1,a=1LL*a*a%mod)if(b&1)ret=1LL*ret*a%mod;
	return ret;
}
int pre[2*MAXN],inv[2*MAXN];
int C(int n,int m){return 1LL*pre[n]*inv[m]%mod*inv[n-m]%mod;}
int a[MAXN],b[MAXN],c[MAXN],ln1,ln2,ln3;
char ch1[MAXN],ch2[MAXN];
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int f[MAXN][MAXN];
int main()
{
	pre[0]=1;for(int i=1;i<2*MAXN;i++)pre[i]=1LL*pre[i-1]*i%mod;
	inv[2*MAXN-1]=pow_mod(pre[2*MAXN-1],mod-2);
	for(int i=2*MAXN-2;i>=0;i--)inv[i]=1LL*inv[i+1]*(i+1)%mod;
	scanf("%s",ch1+1);scanf("%s",ch2+1);int len=strlen(ch1+1);
	int ln1=0,ln2=0,ln3=0;
	for(int i=1;i<=len;i++)if(ch1[i]=='1'||ch2[i]=='1')
	{
		if(ch1[i]=='1'&&ch2[i]=='1')++ln1;
		else if(ch1[i]=='1')++ln2;
		else ++ln3;
	}
	f[0][0]=1;
	for(int j=1;j<=ln2;j++)f[0][j]=1LL*f[0][j-1]*(ln2-j+1)%mod*(ln2-j+1)%mod;
	for(int i=1;i<=ln1;i++)for(int j=1;j<=ln2;j++)
		f[i][j]=(1LL*f[i-1][j]*(ln1-i+1)*j%mod+1LL*f[i][j-1]*(ln2-j+1)%mod*(ln2-j+1)%mod)%mod;
	int ans=0;
	for(int i=0;i<=ln1;i++)
		ad(ans,1LL*f[i][ln2]*pre[ln1-i]%mod*pre[ln1-i]%mod*C(ln1-i+(ln2+i),ln2+i)%mod);
	pr2(ans);
	return 0;
}