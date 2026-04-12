#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
LL n,a[55],la[55];
int main()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	LL ans=0,cnt=0;
	bool flag=true;
	while(flag)
	{
		flag=false;
		LL k=cnt;cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]+=k-la[i];
			LL tot=a[i]/n;a[i]%=n;
			la[i]=tot;ans+=tot;cnt+=tot;
			if(la[i]) flag=true;
		}
	}
	printf("%lld",ans);
}