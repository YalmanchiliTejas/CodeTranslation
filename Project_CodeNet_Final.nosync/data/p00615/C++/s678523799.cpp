#include<cstdio>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
	int n,m,i,a[10000],b[10000],c[20000],d[20000];
	while(scanf("%d%d",&n,&m),m||n)
	{
		for(i=0;i<n;++i)scanf("%d",&a[i]);
		for(i=0;i<m;++i)scanf("%d",&b[i]);
		merge(a,a+n,b,b+m,c);
		adjacent_difference(c,c+n+m,d);
		printf("%d\n",*max_element(d,d+m+n));
	}
	return 0;
}