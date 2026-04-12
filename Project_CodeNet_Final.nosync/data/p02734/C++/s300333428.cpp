#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
#define N 4000
using namespace std;
int n, p;
int a[N];

int barket[N];

int ans;

signed main () {
	cin >> n >> p;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	for (int i = 1; i <= n; i ++) {
		if (a[i] > p) continue;
		(ans += (n - i + 1ll) * barket[p - a[i]]) %= MOD;
		if (a[i] == p) (ans += (n - i + 1ll) * i) %= MOD;
		for (int j = p; j >= a[i]; j --) {
			(barket[j] += barket[j-a[i]]) %= MOD;
		}
		(barket[a[i]] += i) %= MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}
