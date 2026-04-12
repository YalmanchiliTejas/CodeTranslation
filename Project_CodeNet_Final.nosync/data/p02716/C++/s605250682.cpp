#include <bits/stdc++.h>
#define int long long
#define N (int) 3e5
#define INF (int) 1e18
using namespace std;
int n;
int a[N];

int sum1[N], sum2[N], sum3[N];

signed main () {
//	freopen ("sample.in", "r", stdin);
//	freopen ("ABC162F.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	sum1[1] = a[1], sum1[2] = a[2];
	for (int i = 3; i <= n; i ++) {
		sum1[i] = sum1[i-2] + a[i];
	}
	sum2[n] = a[n], sum2[n-1] = a[n-1];
	for (int i = n-2; i >= 1; i --) {
		sum2[i] = sum2[i+2] + a[i];
	}
	
	int ans = -INF;
	for (int i = 1; i+3 <= n; i += 2) {
		ans = max (ans, sum1[i] + sum2[i+3]);
	}
	
	for (int i = 1; i <= n; i ++) sum3[i] = - INF;
	
	if (n % 2 == 0) {
		ans = max (ans, max (sum1[n], sum1[n-1]));
		cout << ans << endl;
	} else {
		int tmp = INF;
		for (int i = 1; i <= n; i += 2) tmp = min (tmp, a[i]);
		ans = max (ans, max (sum1[n-1], sum1[n]-tmp));
		
		for (int i = 2; i+3 <= n; i += 2) ans = max (ans, sum1[i] + sum2[i+3]);
		
		
		for (int i = n-3; i >= 2; i -= 2) sum3[i] = max (sum3[i+2], sum2[i+3]) + a[i];
		for (int i = 1; i+6 <= n; i += 2) ans = max (ans, sum1[i] + sum3[i+3]);
		
		cout << ans << endl;
	}
	
	return 0;
}