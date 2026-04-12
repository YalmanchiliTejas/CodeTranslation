#include <bits/stdc++.h>

#define int long long 

using namespace std;

void solve()
{
	int n;
	cin>>n;
	if(n<=29)
	{
		cout << "No";
	}
	else
		cout << "Yes"<< endl;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	//int t;cin >> t;while(t--)
		solve();

	return 0;
}