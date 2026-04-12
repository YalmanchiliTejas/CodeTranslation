#include<cstdio>
#include<iostream>
using namespace std;
long long n,k,ans;
int main()
{
	cin>>n>>k;
	if(k==0)
	{
		cout<<n*n<<endl;
		return 0;
	}
	for(int i=k+1;i<=n;i++)
	{
		ans+=(n/i)*(i-k)+max((n%i-k+1),(long long)0);
	}
	cout<<ans;
	return 0;
}