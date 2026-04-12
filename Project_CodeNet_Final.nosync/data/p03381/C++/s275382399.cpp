#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,id;
}a[200010];
int ans[200010];
bool cmp(node x,node y)
{
	return (x.x<y.x)||(x.x==y.x&&x.id<y.id);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
	{
		if (i+i<=n) ans[a[i].id]=a[n/2+1].x;
		else ans[a[i].id]=a[n/2].x; 
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
 } 