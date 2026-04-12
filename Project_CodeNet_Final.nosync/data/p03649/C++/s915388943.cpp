#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL i,j,k,n,f,trs,bgs,ans;
LL a[55];
int main()
{
	scanf("%lld",&n);
	for (i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	f=0;
	while (!f)
	{
		f=1;
		for (i=1;i<=n;++i)
			if (a[i]>(n<<1))
			{
				f=0;
				trs=(a[i]-(n<<1)-1)/n+1;
				ans+=trs;
				a[i]-=trs*n;
				for (j=1;j<=n;++j)
					if (i!=j)
						a[j]+=trs;
			}
	}
	while (true)
	{
		bgs=1;
		for (i=2;i<=n;++i)
			if (a[bgs]<a[i])
				bgs=i;
		if (a[bgs]<n)
			break;
		else
		{
			++ans;
			a[bgs]-=n;
			for (i=1;i<=n;++i)
				if (i!=bgs)
					++a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}