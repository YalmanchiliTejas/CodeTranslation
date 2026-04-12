#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
long long a[55],tot;
int cmp(long long x,long long y)
{
	return x>y;
}
int n;long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	while(a[1]>=n)
	{
		for(int i=1;i<=n;i++)
		{
			long long x=a[i]/n;
			ans+=x;
			a[i]%=n;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				a[j]+=x;
			}
		}
		sort(a+1,a+n+1,cmp);
	}
	cout<<ans;
}
