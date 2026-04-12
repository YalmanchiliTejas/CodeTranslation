#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, h[21];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	int res = 0, mm = 0;
	for (int i = 1; i <= n; ++i) {
		if (h[i] >= mm) res++;
		mm = max(mm, h[i]);
	}
	cout << res;
	return 0;
}
