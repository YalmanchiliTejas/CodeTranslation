#include<bits/stdc++.h>
using namespace std;
const long long LAR=1e16;
long long a[55],b[55];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	while(true)
	{
		long long res=0;
		for(int i=1;i<=n;i++)
		{
			res+=a[i]/n;
			b[i]=a[i]/n;
			a[i]%=n;
			a[i]-=b[i];
		}
		if(res==0)break;
		ans+=res;
		for(int i=1;i<=n;i++)a[i]+=res;
	}
	cout<<ans<<endl;
	return 0;
}