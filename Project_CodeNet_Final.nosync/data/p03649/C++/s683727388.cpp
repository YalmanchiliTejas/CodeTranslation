#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long n;
vector<long>a;
long ans;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long x;cin>>x;a.push_back(x);
	}
	while(1)
	{
		long s=0;
		for(int i=0;i<n;i++)s+=a[i]/n;
		if(s==0)break;
		ans+=s;
		for(int i=0;i<n;i++)a[i]-=a[i]/n*n-s+a[i]/n;
	}
	cout<<ans<<endl;
}