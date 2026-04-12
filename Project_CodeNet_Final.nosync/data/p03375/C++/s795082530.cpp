#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
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
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
int m,S[3010][3010];
inline int power(int a,int b,int mod)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}return ans;
}
int fac[3010],inv[3010];
inline int C(int n,int M){return 1LL*fac[n]*inv[M]%m*inv[n-M]%m;}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n=read(),ans=0;m=read();
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=i;j++)S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j%m)%m;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1LL*fac[i-1]*i%m;inv[n]=power(fac[n],m-2,m);
	for(int i=n;i>=1;i--)inv[i-1]=1LL*inv[i]*i%m;
	int id=1;
	for(int i=0;i<=n;i++)
	{
		int uf=power(2,n-i,m),now=1,sum=0;
		for(int j=0;j<=i;j++)sum=(sum+1LL*S[i+1][j+1]*now%m)%m,now=1LL*now*uf%m;
		sum=1LL*sum*C(n,i)%m*power(2,power(2,n-i,m-1),m)%m;
		ans=(ans+(id*sum+m)%m)%m,id=-id;
	}pr2(ans);
	return 0;
}