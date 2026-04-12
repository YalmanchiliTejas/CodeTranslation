#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans;
signed main()
{
	cin>>n>>k;
	if(!k)
	{
		cout<<n*n;
		return 0;
	}
	for(int b=k+1;b<=n;++b)
	{
		ans+=max((n/b*b)/b,0ll)*(b-k);
		ans+=max(n%b-k+1,0ll);
	}
	cout<<ans;
	return 0;
}