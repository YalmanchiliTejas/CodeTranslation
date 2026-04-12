#include<bits/stdc++.h> 
using namespace std;
long long n,k,ans;
int main()
{
	cin>>n>>k;
	for(long long i=k+1;i<=n;i++)
	{
		if(!(n%i))ans+=(i-k)*(n/i);
		else{if(k==0)ans--;ans+=(i-k)*(n/i)+max(0ll,n%i-k+1);}
	}
	cout<<ans; 
}