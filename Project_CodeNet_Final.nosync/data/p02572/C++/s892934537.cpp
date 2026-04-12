#include<iostream>
using namespace std;
#define N 1000000007
long long a[10000000];
long long m[20000000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		
		cin>>a[i];
		m[i]=(m[i-1]+a[i]);
	}
	long long sum=0;
	for(int i=2;i<n;i++)
	{
		sum+=(a[i]%N)*(m[i-1]%N)%N;
		sum%=N;
	}
	sum+=(a[0]%N)*(a[1]%N);
	sum%=N;
	cout<<sum;
}