//周期性で殴る
#include <iostream>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;

int n;
int a[50];

signed main() {
	int i, j;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	
	//for (int k = 0; k < n; k++) cout << a[k] << " "; cout << endl;
	
	int ans = 0;
	for (i = 0; i < n - 1; i++) {
		int cnt = min(a[i] / (n - i), (a[i] - a[i + 1]) / (n + 1));
		for (j = 0; j <= i; j++) {
			a[j] -= (n - i) * cnt;
			ans += cnt;
		}
		for (j = i + 1; j < n; j++) {
			a[j] += (i + 1) * cnt;
		}
	}
	sort(a, a + n, greater<int>());
	
	//cout << ans << endl;
	//for (int k = 0; k < n; k++) cout << a[k] << " "; cout << endl;
	
	
	int cnt = max(0LL, a[n - 1] - (n - 1));
	for (i = 0; i < n; i++) {
		a[i] -= cnt;
		ans += cnt;
	}
	
	//cout << ans << endl;
	//for (int k = 0; k < n; k++) cout << a[k] << " "; cout << endl;
	
	
	//最後にシミュレーション
	while (true) {
		sort(a, a + n, greater<int>());
		if (a[0] <= n - 1) { break; }
		ans++;
		a[0] -= n;
		for (i = 1; i < n; i++) a[i]++;
	}
	
	cout << ans << endl;
	return 0;
}