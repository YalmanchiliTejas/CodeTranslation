#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	long long res = 0;

	cin >> n >> k;
	for (int b = k + 1; b <= n; ++b) {
		for (int i = k; i <= n; i += b) {
			int j = min(n, i - k + b - 1);
			res += max(0, j - i + 1);
		}
	}

	cout << res - ((k == 0) ? n : 0) << endl;
}