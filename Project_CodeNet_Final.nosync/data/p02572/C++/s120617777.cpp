#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int mod = 1e9+7;

void solve()
{
	int n;
	cin >> n;
	ll sum = 0;
	ll tot = 0;
	for(int i = 0; i<n; i++)
	{
		int t;
		cin >> t;
		(tot += t * sum) %= mod;
		(sum += t) %= mod;
	}
	cout << tot << "\n";
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
