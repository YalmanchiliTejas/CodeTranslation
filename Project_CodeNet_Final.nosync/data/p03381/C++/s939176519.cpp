#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct T{
	int x,id;
}a[210000];
int f[210000];
int cmp(T x,T y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if (i<=(n-1)/2+(n-1)%2) f[a[i].id]=a[(n-1)/2+(n-1)%2+1].x;
		else f[a[i].id]=a[(n-1)/2+(n-1)%2].x;
	}
	for (int i=1;i<=n;i++) printf("%d\n",f[i]);
 } 