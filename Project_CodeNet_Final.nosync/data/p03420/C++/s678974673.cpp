#include<iostream>
#define int long long
using namespace std;
signed main()
{
	int n,k,ans=0;
	cin>>n>>k;
	for(int b=k+1;b<=n;b++)
	{
		int x=(n+1)/b;
		ans+=x*(b-k);
		if(x*b+k<=n)ans+=(n-k-x*b+1);
		if(!k)ans--;
	}
	cout<<ans<<endl;
	return 0;
}
