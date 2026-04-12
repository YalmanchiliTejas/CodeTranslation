#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	while (1) {
		if (n == 0 && l == 0 && r == 0)break;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 0;

		for (int x = l; x <= r; x++) {
			for (int i = 0; i < n; i++) {
				if (x%a[i] == 0) {
					if (i % 2 == 0) {
						ans++;
						break;
					}
					else break;
				}
				if (i == n-1 && n % 2 == 0)ans++;
			}
		}
		cout << ans << endl;
		cin >> n >> l >> r;
	}
}
