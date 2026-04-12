#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)break;
		int a[n];
		int ans = 0;
		for (int i = 0;i < n;i++) {
			cin >> a[i];
			ans += a[i];
		}
		sort(a, a + n);
		ans -= a[0] + a[n - 1];
		ans /= n - 2;
		cout << ans << endl;
	}
}
