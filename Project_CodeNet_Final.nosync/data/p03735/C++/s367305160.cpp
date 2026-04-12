#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int N=400005;
struct node
{
	int num,bl,ty;
}a[N];
int n,i,j,k,x,y,c[N];
bool v[N][2];
long long ans=1ll<<60;
bool cmp(node a,node b)
{
	if(a.num!=b.num)
		return a.num<b.num;
	return a.ty<b.ty;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a[2*i-1].num,&a[2*i].num);
		if(a[2*i-1].num>a[2*i].num)
			swap(a[2*i-1].num,a[2*i].num);
		a[2*i-1].bl=a[2*i].bl=i;
		a[2*i-1].ty=0,a[2*i].ty=1;
	}
	sort(a+1,a+1+2*n,cmp);
	for(i=1;i<=2*n;++i)
		if(a[i].ty==1)
			break;
	if(i-1>=n)
		ans=min(ans,1ll*(a[n].num-a[1].num)*(a[2*n].num-a[n+1].num));
	else
	{
		for(j=i,k=i-1;;++j)
			if(a[j].ty==0)
			{
				++k;
				if(k>=n)
					break;
			}
		ans=min(ans,1ll*(a[j].num-a[1].num)*(a[2*n].num-a[i].num));
	}
	if(a[1].bl!=a[2*n].bl)
	{
		for(x=2;;++x)
			if(a[x].bl==a[1].bl)
				break;
		for(y=2*n-1;;--y)
			if(a[y].bl==a[2*n].bl)
				break;
		if(x>y)
			swap(x,y);
		for(i=2,j=2,k=0;i<2*n;++i)
		{
			while(j<2*n)
			{
				if(c[a[j].bl]==0)
					++k;
				c[a[j].bl]++;
				if(k>=n)
					break;
				++j;
			}
			if(j>=2*n)
				break;
			ans=min(ans,1ll*(a[2*n].num-a[1].num)*(a[max(y,j)].num-a[min(x,i)].num));
			c[a[i].bl]--;
			if(c[a[i].bl]==0)
				--k;
		}
	}
	printf("%lld",ans);
	return 0;
}
