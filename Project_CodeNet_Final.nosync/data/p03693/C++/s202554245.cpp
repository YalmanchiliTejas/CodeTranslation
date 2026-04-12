#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int r = 0;
	for (int i = 0; i < 3; i++) {
		int v; cin >> v;
		r = 10 * r + v;
	}
	cout << (r % 4 == 0 ? "YES" : "NO") << '\n';

	return 0;
}
