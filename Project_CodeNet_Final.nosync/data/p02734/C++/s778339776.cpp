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
inline int ad(int x){return x>=mod?x-mod:x;}
int f[3010];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
   	int n=read(),m=read(),ans=0;
   	for(int i=1;i<=n;i++)
   	{
   		int d=read();
		if(d<m)ans=ad(ans+1LL*f[m-d]*(n-i+1)%mod);
		if(d==m)ans=ad(ans+1LL*i*(n-i+1)%mod);
   		for(int j=m;j>d;j--)f[j]=ad(f[j]+f[j-d]);
   		f[d]=ad(f[d]+i);
   	}pr2(ans);
    return 0;
}