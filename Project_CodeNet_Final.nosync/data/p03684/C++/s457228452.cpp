#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define N 100010
struct pp{int x,y,i;
}p[N];
struct aa{int x,y,z;
}a[N*2];
int f[N];
long long ans;
int i,n,cnt,x,y,fx,fy;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while (ch<'0'||ch>'9')
		{
			if (ch=='-') f=-1;
			ch=getchar();
		}
	while (ch<='9'&&ch>='0')
		{
			x=x*10+ch-'0';
			ch=getchar();
		}
	return x*f;
}
inline void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}
inline bool cmp1(pp a,pp b)
{
	return a.x<b.x;
}
inline bool cmp2(pp a,pp b)
{
	return a.y<b.y;
}
inline void add(int x,int y,int z)
{
	cnt++;
	a[cnt].x=x;
	a[cnt].y=y;
	a[cnt].z=z;
}
inline bool cmp(aa a,aa b)
{
	return a.z<b.z;
}
inline int getf(int x)
{
	if (x==f[x]) return x;
	return f[x]=getf(f[x]);
 } 
int main()
{
	n=read();
	for (i=1;i<=n;i++)
	{
		p[i].x=read();
		p[i].y=read();
		p[i].i=i;
		f[i]=i;
	}
	sort(p+1,p+n+1,cmp1);
	for (i=1;i<n;i++) add(p[i].i,p[i+1].i,abs(p[i].x-p[i+1].x));
	sort(p+1,p+n+1,cmp2);
	for (i=1;i<n;i++) add(p[i].i,p[i+1].i,abs(p[i].y-p[i+1].y)); 
	sort(a+1,a+cnt+1,cmp);
	for (i=1;i<=cnt;i++)
	{
		x=a[i].x;
		y=a[i].y;
		fx=getf(x);
		fy=getf(y);
		if (fx==fy) continue;
		ans+=a[i].z;
		f[fx]=fy;
	}
	write(ans);
}