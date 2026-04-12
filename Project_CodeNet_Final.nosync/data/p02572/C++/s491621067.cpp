#include<iostream>
#include<string>
using namespace std;
long long n,a[200010];
const int mod=1000000007;
int main()
{
	int n;
	cin>>n;
	long long s=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum-=a[i];
		s=(((a[i]%mod)*(sum%mod)%mod)+s)%mod;
	}
	cout<<s<<endl;
	return 0;		
}