#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> h;
	int n, max = 0, cnt = 0;
	cin >> n;
	h.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		if (max <= h[i])
		{
			cnt++;
			max = h[i];
		}
	}
	cout << cnt << endl;
	return 0;
}
