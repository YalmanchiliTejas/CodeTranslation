#include <cstdio>
#include <algorithm>

using namespace std;

struct point
{
	int x,y,z;
};

point p[300000],e[300000];
int f[300000];
int i,k,n,fx,fy;
long long s;

inline bool cmp1(point x,point y)
{
	return x.x<y.x;
}

inline bool cmp2(point x,point y)
{
	return x.y<y.y;
}

inline bool cmp3(point x,point y)
{
	return x.z<y.z;
}

inline int getfather(int x)
{
	if (f[x]==x)
		return x;
	else
		return f[x]=getfather(f[x]);
}

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),p[i].z=i;
	sort(p+1,p+n+1,cmp1);
	for (i=1;i<n;i++)
		k++,e[k].x=p[i].z,e[k].y=p[i+1].z,e[k].z=p[i+1].x-p[i].x;
	sort(p+1,p+n+1,cmp2);
	for (i=1;i<n;i++)
		k++,e[k].x=p[i].z,e[k].y=p[i+1].z,e[k].z=p[i+1].y-p[i].y;
	sort(e+1,e+k+1,cmp3);
	for (i=1;i<=n;i++)
		f[i]=i;
	for (i=1;i<=k;i++)
	{
		fx=getfather(e[i].x);
		fy=getfather(e[i].y);
		if (fx!=fy)
		{
			f[fx]=fy;
			s=s+e[i].z;
		}
	}
	printf("%lld",s);
	return 0;
}