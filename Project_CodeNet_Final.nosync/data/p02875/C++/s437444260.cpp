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
const int mod=998244353;
inline int dec(int x){return x<0?x+mod:x;}
inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}return ans;
}
int fac[10000010],inv[10000010];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	fac[0]=1;
	int n=read(),ans=power(3,n);
	for(int i=1;i<=n;i++)fac[i]=1LL*fac[i-1]*i%mod;inv[n]=power(fac[n],mod-2);
	for(int i=n;i>=1;i--)inv[i-1]=1LL*inv[i]*i%mod;
	for(int i=n/2+1;i<=n;i++)ans=dec(ans-2LL*inv[i]*power(2,n-i)%mod*inv[n-i]%mod*fac[n]%mod);
	pr2(ans);
	return 0;
}