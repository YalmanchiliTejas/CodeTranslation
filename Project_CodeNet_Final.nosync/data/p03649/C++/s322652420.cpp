#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
#define int long long

int a[55];
int amax(int s) {
	int b = a[0];
	for (int i = 0; i < s; i++) {
		b = max(b, a[i]);
	}
	return b;
}
signed main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)cin >> a[i];

	sort(a, a + k);
	reverse(a, a + k);
	int ans = 0;
	while (amax(k) >= k) {
		for (int i = 0; i <k; i++) {
			int m = a[i] / k;
			for (int j = 0; j < k; j++) {
				if (i != j) {
					a[j] += m;
				}
			}
			a[i] %= k;
			ans += m;
		}
	}
	cout << ans << endl;
	}