#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define regsiter register
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
int x[222222],y[222222]; 
struct in
{
	int l,r;
}t[222222];
bool operator <(const in&x,const in &y)
{
	return x.l<y.l;
}
int main()
{
	int n=io::F(),mx=0,mn=0x3f3f3f3f,mxpl,mnpl;
	for(register int i=1;i<=n;++i)
	{
		x[i]=io::F(),y[i]=io::F();
		if(x[i]>y[i])std::swap(x[i],y[i]);
		if(cmin(mn,x[i]))mnpl=i;
		if(cmax(mx,y[i]))mxpl=i;
	}
	int r1=mn,l2=mx;
	for(register int i=1;i<=n;++i)
		cmax(r1,x[i]),cmin(l2,y[i]);
	long long ans=(long long)(r1-mn)*(mx-l2);
	if(mnpl==mxpl)return!printf("%lld\n",ans);
	int L=y[mnpl],R=x[mxpl];
	if(L>R)std::swap(L,R);
	int pt=0;
	for(register int i=1;i<=n;++i)
	{
		if(y[i]<L)L=y[i];
		if(x[i]>R)R=x[i];
	}
	for(register int i=1;i<=n;++i)
		if(x[i]<L&&y[i]>R)t[++pt]=(in){x[i],y[i]};
	std::sort(t+1,t+pt+1);
	int max=R;
	long long dis=mx-mn; 
	if(pt==0)cmin(ans,dis*(R-L));
	for(register int i=1;i<=pt;++i)
	{
		cmin(ans,dis*(max-t[i].l));
		cmax(max,t[i].r);
	}
	printf("%lld\n",ans);
	return 0;
}


