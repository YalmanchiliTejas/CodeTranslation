#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=200005;
struct node { int x,y; } a[N];
LL an;
int z[N],s[N],i,j,k,n,m,x,y,l1,l2,r1,r2,l,r,L,R;
bool P;
char c;

inline char getc()
{
	#define VV 10000000
	static char s[VV],*l=s,*r=s;
	if (l==r)
		l=s,r=s+fread(s,1,VV,stdin);
	return l==r?0:*l++;
}

int read(){ int z=0; do c=getc(); while (c<'0'||c>'9'); while (c>='0'&&c<='9') z*=10,z+=c-'0',c=getc(); return z; }

bool cmp(node a,node b){ return a.x<b.x; }

void solve()
{
	sort(a+1,a+n+1,cmp);
	int D=1e9;
	for (i=1;i<=n;++i)
		an=min(an,(LL)(R-L)*(r1-min(a[i].x,D))),
		D=min(D,a[i].y),
		r1=max(r1,a[i].y);
}

int main()
{
	n=read(),L=1e9;
	for (i=1;i<=n;++i)
	{
		a[i]=(node){read(),read()};
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
		L=min(L,a[i].x),R=max(R,a[i].y);
	}
	if (n==1||L==R)
	{
		puts("0");
		return 0;
	}
	l1=l2=1e9;
	for (i=1;i<=n;++i)
		x=a[i].x,y=a[i].y,
		l1=min(l1,x),r1=max(r1,x),
		l2=min(l2,y),r2=max(r2,y);
	an=(LL)(r1-l1)*(r2-l2);
	solve();
	printf("%lld\n",an);
	return 0;
}