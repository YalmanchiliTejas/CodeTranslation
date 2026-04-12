#include <cstdio> 
#include <iostream> 
#include <algorithm> 
using namespace std;
const int MOD=1e9+7;
inline int mul(int a,int b)
{return 1LL*a*b%MOD;}
inline int add(int a,int b)
{a+=b;return a>=MOD?a-MOD:a;}
inline int sub(int a,int b)
{a-=b;return a<0?a+MOD:a;}
int p2(int b)
{
	int a=2,ans=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1)ans=mul(ans,a);
	return ans;
}
const int Q=1<<8;
int cmp[Q],a[Q];
struct dt{
	int f,g;
	dt(){}
	dt(int mus,int no)
	{f=mus,g=no;}
};
dt Gans(int l,int r,int lim)
{
	int mn=MOD,ct=0;
	for(int i=l;i<=r;i++)
		if(a[i]==mn)++ct;
		else if(a[i]<mn)ct=1,mn=a[i];
	if(ct==r-l+1)return dt(sub(p2(ct),2),p2(mn-lim));
	int p0=1,p1=1;
	for(int lst=0,i=l;i<=r+1;i++)
		if(lst&&(a[i]==mn||i>r)){
			dt now=Gans(lst,i-1,mn);
			lst=0;
			p0=mul(p0,add(now.f,mul(now.g,2)));
			p1=mul(p1,now.g);
		}
		else if((!lst)&&a[i]>mn)lst=i;
	p0=sub(p0,p1);
	return dt(add(mul(p0,p2(ct)),mul(p1,sub(p2(ct),2))),mul(p1,p2(mn-lim)));
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dt als=Gans(1,n,0);
	printf("%d",add(als.f,als.g));
	return 0;
}