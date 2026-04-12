#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h.at(i);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool canW = true;
		for (int j = 0; j < i; j++)
		{
			if (h.at(i) < h.at(j))
			{
				canW = false;
				break;
			}
		}
		if (canW)
			ans++;
	}
	cout << ans << endl;
}