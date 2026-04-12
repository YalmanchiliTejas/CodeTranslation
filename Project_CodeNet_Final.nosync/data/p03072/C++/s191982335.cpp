#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, max_h, res = 1;
	cin >> n;
	cin >> x;
	max_h = x;
	--n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x >= max_h)
		{
			max_h = x;
			++res;
		}	
	}
	cout << res;
	return 0;
}