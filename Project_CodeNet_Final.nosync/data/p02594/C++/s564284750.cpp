#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define mod 1000000007
#define pb push_back
void dora()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	dora(); fast;

	int t = 1; //cin >> t;
	while (t--)
	{
		int x; cin >> x;
		if (x >=  30)cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}