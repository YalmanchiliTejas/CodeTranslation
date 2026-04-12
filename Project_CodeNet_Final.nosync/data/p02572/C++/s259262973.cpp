#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,sum=0;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int x=a[0];
	for(long long int i=1;i<n;i++)
	{
		sum = (sum +((long long int )a[i]*x))%1000000007;
		x = (x+a[i])%1000000007;
	}
	cout<<sum<<endl;
	return 0;
}