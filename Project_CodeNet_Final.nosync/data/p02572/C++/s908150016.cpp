#include<iostream>
using namespace std;
#define N 1000000007
long long a[1000000];
int main()
{
	int n;
	cin>>n;
	long long m[10000000];
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		m[i]=(m[i-1]+a[i]);
	}
	long long sum=0;
	for(int i=3;i<=n;i++)
	{
		/*
		long long a=(m[i]-m[i-1])%N;
		long long b=(m[n-1]-m[i])%N;
//		cout<<i+1<<":   a-"<<a<<"  b-"<<b<<endl;
		long long q=(a*b)%N;
		sum+=q%N;
		sum=sum%N;
		*/
		sum+=(a[i]%N)*(m[i-1]%N)%N;
		sum%=N;
	}
	
	sum+=(a[1]%N)*(a[2]%N);
	sum%=N;
	cout<<sum;
}