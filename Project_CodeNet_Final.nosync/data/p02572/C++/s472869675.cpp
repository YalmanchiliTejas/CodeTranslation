#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{	
int n;
cin>>n;
int a[n];
int sum=0;
for(int i=0;i<n;i++)
{
	cin>>a[i];
	sum+=a[i];
		sum%=(1000000000+7);
	}
	int ans=0;
	for(int i=0;i<n;i++)
{
	sum-=a[i];
	if(sum<0)
	sum+=1000000000+7;
	;ans+=a[i]*sum;
	ans%=(1000000000+7);
}
		cout<<ans<<endl;		
}