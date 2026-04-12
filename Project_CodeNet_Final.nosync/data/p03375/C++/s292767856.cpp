#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 3010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,p,ans,inv[maxn],S[maxn][maxn];
int add(int x,int y)
{
	return (x+y)%p;
}
int sub(int x,int y)
{
	return (x-y+p)%p;
}
int mul(int x,int y)
{
	return 1ll*x*y%p;
}
int fpow(int x,int y,int P=p)
{
	int res=1;
	while(y)
	{
		if(y&1)
			res=1ll*res*x%P;
		x=1ll*x*x%P;
		y>>=1;
	}
	return res;
}
int main()
{
	read(n,p);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=mul(p-p/i,inv[p%i]);
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=add(mul(j,S[i-1][j]),S[i-1][j-1]);
	int a=1,b=fpow(2,n),inv2=(p+1)/2;
	for(int i=0;i<=n;i++)
	{
		int o=0;
		for(int j=0,k=1;j<=i;j++,k=mul(k,b))
			o=add(o,mul(S[i+1][j+1],k));
		if(i&1)ans=sub(ans,mul(mul(a,fpow(2,fpow(2,n-i,p-1))),o));
		else ans=add(ans,mul(mul(a,fpow(2,fpow(2,n-i,p-1))),o));
		a=mul(a,mul(inv[i+1],n-i));
		b=mul(b,inv2);
	}
	printf("%d\n",ans);
    return 0;
}
