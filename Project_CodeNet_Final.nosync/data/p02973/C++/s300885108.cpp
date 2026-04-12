#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],f[N],ans,n;
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=1;i--)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(f[ans]<=a[i])f[++ans]=a[i];
		else f[upper_bound(f+1,f+1+ans,a[i])-f]=a[i];
	printf("%d",ans);
	return 0;
}