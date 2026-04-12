#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	while (cin >> n, n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		a.pop_back();
		reverse(a.begin(), a.end());
		a.pop_back();
		cout << accumulate(a.begin(), a.end(), 0) / (n - 2) << endl;
	}
	return 0;
}

