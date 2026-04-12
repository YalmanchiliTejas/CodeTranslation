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
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(int x){write(x);putchar('\n');}
const int MAXN=3005;
int S[MAXN][MAXN],C[MAXN][MAXN];
int n,mod;
void init()
{
	S[0][0]=1;
	for(int i=0;i<MAXN;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
			S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%mod;
		}
	}
}
int pow_mod(int a,int b,int md)
{
	int ret=1;
	while(b)
	{
		if(b&1)ret=1LL*ret*a%md;
		a=1LL*a*a%md;b>>=1;
	}
	return ret;
}
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
int main()
{
	n=read();mod=read();
	init();int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=1LL*pow_mod(2,pow_mod(2,n-i,mod-1),mod)*C[n][i]%mod,num=0;
		for(int k=0;k<=i;k++)ad(num,1LL*pow_mod(pow_mod(2,n-i,mod),k,mod)*S[i+1][k+1]%mod);
		if(i&1)dl(ans,1LL*sum*num%mod);
		else ad(ans,1LL*sum*num%mod);
	}
	pr2(ans);
	return 0;
}
