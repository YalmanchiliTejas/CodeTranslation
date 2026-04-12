#include<cstdio>
using namespace std;
const int N=3*100000;
int n ,a[N],b[N],c[N],d[N],tot=0,tot2=0;
bool tag=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(tag==0)
		{
			tot++;b[tot]=a[i];tag=1;
		}
		else
		{
			tot2++;c[tot2]=a[i];tag=0;
		}
	}
	int tot3=0;
	for(int i=tot2;i>=1;i--)
	{
		d[++tot3]=c[i];
	}
	if(tag==0)
	{
		for(int i=1;i<=tot3;i++) printf("%d ",d[i]);
		for(int i=1;i<=tot;i++) printf("%d ",b[i]);
	}
	else
	{
		for(int i=tot;i>=1;i--) printf("%d ",b[i]);
		for(int i=1;i<=tot2;i++) printf("%d ",c[i]);
	}
}