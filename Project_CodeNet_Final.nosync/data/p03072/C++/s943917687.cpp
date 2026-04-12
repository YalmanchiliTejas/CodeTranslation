#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> hs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> hs[i];
	}
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		bool ok = 1;
		for (int j = 0; j < i; j++)
		{
			ok &= hs[j] <= hs[i];
		}
		ans += ok;
	}
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
