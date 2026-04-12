#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, l, r;
	while (cin >> n >> l >> r && n) {
		vector<int> a(n);
		for (auto&& i : a) {
			cin >> i;
		}
		int ans = 0;
		bool found;
		for (int i = l; i <= r; i++) {
			found = false;
			for (int j = 0; j < n; j++) {
				if (i % a[j]) continue;
				found = true;
				if (j % 2 == 0) {
					ans++;
				}
				break;
			}
			if (!found) {
				ans += !(n % 2);
			}
		}
		cout << ans << "\n";
	}
}
