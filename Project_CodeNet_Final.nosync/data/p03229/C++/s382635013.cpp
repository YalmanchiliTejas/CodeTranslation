#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
int main() {
	long long n, k[100005], ans;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	sort(k, k + n);
	int a = 0, b = n - 1, aa, bb;
	ans = k[n - 1] - k[0];
	while (a < b) {
		aa = a + 1;
		bb = b - 1;
		if (aa == bb) {
			if (k[b] - k[aa] > k[bb] - k[a]) {
				ans += k[b] - k[aa];
				a = aa;
			}
			else {
				ans += k[bb] - k[a];
				b = bb;
			}
		}
		else {
			ans += k[b] - k[aa], ans += k[bb] - k[a];
			a = aa;
			b = bb;
		}
	}
	cout << ans << endl;
}