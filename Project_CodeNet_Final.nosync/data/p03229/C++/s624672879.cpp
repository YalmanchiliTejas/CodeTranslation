#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005];
int N;
int main()
{
	while(cin>>N)
	{
		for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
		sort(a,a+N);
		long long ans=0;
		long long sum1=0,sum2=0,sum3=0;
		if(N&1)
		{
			for(int i=0;i<N/2;i++)
			sum1+=a[i];
			for(int i=N/2+1;i<N;i++)
			sum2+=a[i];
			sum3=max(a[N/2-1]-a[N/2],a[N/2]-a[N/2+1]);
			ans=2*sum2-2*sum1+sum3;
		}
		else
		{
			for(int i=0;i<N/2;i++)
			sum1+=a[i];
			for(int i=N/2;i<N;i++)
			sum2+=a[i];
			sum3=a[N/2-1]-a[N/2];
			ans=2*sum2-2*sum1+sum3;
		}
		cout<<ans<<endl;
	}
	return 0;
}