#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	bool ok[2] = {};
	for (int i = 0; i < 2; i++)
	{
		long long m = 0;
		for (int cnt = 0; cnt < n - 1; cnt++)
			if (cnt * 10 <= m)
				m = max(m, cnt * 10 + vec[cnt]);
		if (10 * (n - 1) <= m)
			ok[i] = true;
		if (i == 0)
			reverse(begin(vec), end(vec));
	}
	if (ok[0] && ok[1])
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}

