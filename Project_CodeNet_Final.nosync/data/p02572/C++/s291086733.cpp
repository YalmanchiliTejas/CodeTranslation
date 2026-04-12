#include<bits/stdc++.h>

using namespace std;

#define int		long long

void solve()
{
	int n,ans=0,sum=0;
	cin >>n;
	std::vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i =0;i<n;i++){
		ans += a[i] * sum % 1000000007;
		sum += a[i];
		sum %= 1000000007;
		ans %= 1000000007;
	}
	cout << ans << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	//int t;cin >> t ;while(t--)
	 	solve();
}