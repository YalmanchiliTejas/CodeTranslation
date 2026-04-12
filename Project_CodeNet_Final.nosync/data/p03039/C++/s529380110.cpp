#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
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
int fac[200010],inv[200010];
inline int C(int m,int n){return 1LL*fac[m]*inv[n]%mod*inv[m-n]%mod;}
long long u1,u2;
inline int getval(int n){return (1LL*n*n%mod*(n+1)%mod*u1%mod-1LL*n*(n+1)%mod*(2*n+1)%mod*u2%mod+mod)%mod;}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n=read(),m=read(),k=read();
    fac[0]=1;
    for(int i=1;i<=n*m;i++)fac[i]=1LL*fac[i-1]*i%mod;inv[n*m]=power(fac[n*m],mod-2);
    for(int i=n*m;i>=1;i--)inv[i-1]=1LL*inv[i]*i%mod;
    u1=power(2,mod-2),u2=power(6,mod-2);
    pr2(1LL*C(n*m-2,k-2)*(1LL*m*m%mod*getval(n)%mod+1LL*n*n%mod*getval(m)%mod)%mod);
   	return 0;
}