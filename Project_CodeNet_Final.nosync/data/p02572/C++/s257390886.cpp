#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define mod 1000000007
int main()
{
	int n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long sum = a[n-1];
	long long ans = 0;
	// cout<<"debug"<<endl;
	for(int i=n-2;i>=0;i--)
	{

		ans = (ans + (a[i]*sum)%mod)%mod;
		sum = (sum + a[i])%mod; 
	}
	cout<<ans<<endl;
}