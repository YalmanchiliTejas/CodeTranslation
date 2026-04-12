#include<cstdio>
#define mid ((l+r+1)>>1)
using namespace std;
int n,a[100001],ans,num[100001]; 
inline int rd()
{
	char tmp=getchar();
	int ddd=0;
	while('0'>tmp&&tmp<'9')
	{
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd;
}
inline int Find(int x)
{
	int l=0,r=ans;
	while(l+1<r)
	{
		if(num[mid]>=x)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	num[r]=x;
}
int main()
{
	n=rd();
	num[0]=0x7fffffff;
	for(int i=1;i<=n;++i)
	{
		a[i]=rd();
		if(a[i]<=num[ans])
		{
			num[++ans]=a[i];
		}
		else
		{
			Find(a[i]);
		}
	}
	printf("%d",ans);
	return 0;
}
