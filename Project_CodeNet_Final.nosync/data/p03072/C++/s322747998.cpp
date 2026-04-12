

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	int h = list[0];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (list[i] >= h)
		{
			ans++;
		}
		h = max(h, list[i]);
	}
	cout << ans << "\n";
	return 0;
}