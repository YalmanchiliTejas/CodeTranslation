#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005,INF=2000000000;
int n,a[N],b[N],R_mn,R_mx,B_mn,B_mx;
typedef long long LL;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void ck(int &x,int &y,int c)
{
	x=min(x,c);
	y=max(y,c);
}

LL solve1()
{
	R_mn=INF,R_mx=0;
	B_mn=INF,B_mx=0;
	rep(i,1,n) ck(R_mn,R_mx,min(a[i],b[i])),ck(B_mn,B_mx,max(a[i],b[i]));
	return (LL)(R_mx-R_mn)*(B_mx-B_mn);
}

LL solve2()
{
	R_mn=INF,R_mx=0;
	B_mn=INF,B_mx=0;
	rep(i,1,n) R_mn=min(R_mn,min(a[i],b[i])),R_mx=max(R_mx,max(a[i],b[i]));
	rep(i,1,n)
		B_mn=min(B_mn,max(a[i],b[i]));
	rep(i,1,n)
		if(min(a[i],b[i])>=B_mn) B_mx=max(B_mx,min(a[i],b[i]));
		else B_mx=max(B_mx,max(a[i],b[i]));
	return (LL)(R_mx-R_mn)*(B_mx-B_mn);
}

LL solve3()
{
	R_mn=INF,R_mx=0;
	B_mn=INF,B_mx=0;
	rep(i,1,n) R_mn=min(R_mn,min(a[i],b[i])),R_mx=max(R_mx,max(a[i],b[i]));
	rep(i,1,n)
	{
		if(a[i]==R_mn || a[i]==R_mx) ck(B_mn,B_mx,b[i]);
		else if(b[i]==R_mn || b[i]==R_mx) ck(B_mn,B_mx,a[i]);
	}
	rep(i,1,n)
	{
		if(B_mn<=a[i] && a[i]<=B_mx) continue;
		if(B_mn<=b[i] && b[i]<=B_mx) continue;
		if(min(abs(a[i]-B_mn),abs(a[i]-B_mx))<min(abs(b[i]-B_mn),abs(b[i]-B_mx)))
			ck(B_mn,B_mx,a[i]);
		else ck(B_mn,B_mx,b[i]);
	}
	return (LL)(R_mx-R_mn)*(B_mx-B_mn);
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint(),b[i]=getint();
	printf("%lld\n",min(min(solve1(),solve2()),solve3()));
	return 0;
}