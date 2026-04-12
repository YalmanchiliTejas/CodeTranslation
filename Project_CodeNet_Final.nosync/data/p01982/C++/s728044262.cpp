#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n, l, r;
	while (cin >> n >> l >> r, n) {
		int ans = 0, a[60];
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int y = l; y <= r; y++) {
			int i;
			for (i = 0; i < n; i++) {
				if (y%a[i] == 0)goto a;
			}
			ans += (n % 2 + 1) % 2; goto b;
		a:ans += (i % 2 + 1) % 2;
		b:;
		}
		cout << ans << endl;
	}
}
