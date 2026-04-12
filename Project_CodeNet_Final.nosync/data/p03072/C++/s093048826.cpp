#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int n, k = 1, p, flag, cont, ans = 0;

	cin >> n;

	vector <int> h(n);

	for (int i = 0; i < n; i++) cin >> h[i];

	for (int i = 0; i < n; i++) {
		p = h[i];
		flag = i + 1;
		cont = 0;
		for (int j = 0; j < k; j++) {
			if (h[j] <= h[i]) cont++;
		}
		if (cont == flag) ans++;
		k++;
	}

	cout << ans << '\n';

	return 0;
}