#include <bits/stdc++.h>

using namespace std;

const int N=1e5+233;
long long father[N*2];
long long n;
long long l=0;
long long ans=0;
struct zyy1
{
    long long x,y,num;
}a[N*10];

struct zyy2
{
	long long s,t,val;
}b[N*10];

bool cmp1(zyy1 a,zyy1 b)
{
	return a.x>b.x;
}

bool cmp(zyy2 a,zyy2 b)
{
	return a.val<b.val;
}
bool cmp2(zyy1 a,zyy1 b)
{
	return a.y>b.y;
}

inline long long find(long long x)
{
	if(father[x]==x)return x;
	father[x]=find(father[x]);
	return father[x];
}

int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)father[i]=i;
	for(long long i=1;i<=n;i++)a[i].num=i;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp1);
	

	

	
	
	
	
	
	for(long long i=1;i<=n-1;i++)
	{
		b[++l].s=a[i].num;
		b[l].t=a[i+1].num;
		b[l].val=abs(a[i].x-a[i+1].x);
	}
	sort(a+1,a+n+1,cmp2);
	
	
	for(long long i=1;i<=n-1;i++)
	{
		b[++l].s=a[i].num;
		b[l].t=a[i+1].num;
		b[l].val=abs(a[i].y-a[i+1].y);
	}
	
	
	sort(b+1,b+l+1,cmp);
	
/*	for(int i=1;i<=l;i++)
	{
		cout<<b[i].s<<" ";
	}
	cout<<endl;
	for(int i=1;i<=l;i++)
	{
		cout<<b[i].t<<" ";
	}
	cout<<endl;
	for(int i=1;i<=l;i++)
	{
		cout<<b[i].val<<" ";
	}
	cout<<endl;*/
	
	
	for(long long i=1;i<=l;i++)
	{
		if(find(b[i].s)!=find(b[i].t))
		{
			long long fx=find(b[i].s);
			long long fy=find(b[i].t);
			father[fx]=fy;
			ans+=b[i].val;
		}
	}
	printf("%lld\n",ans);
	return 0;
}