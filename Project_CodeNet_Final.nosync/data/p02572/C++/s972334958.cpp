#include <bits/stdc++.h>
using namespace std;

int main() {
 	long long n;
 	cin >> n;
 	long long a[n + 1], suf[n + 1];
 	for(long long i = 1; i <= n; i++) {
        cin >> a[i];
 	}
 	suf[n] = 0;
 	long long ans = 0, MOD = 1e9 + 7;
 	for(long long i = n - 1; i > 0; i--) {
        suf[i] = suf[i + 1] + a[i + 1];
        suf[i] %= MOD;
 	}
 	for(long long i = 1; i <= n; i++) {
        ans += (suf[i] * a[i]);
        ans %= MOD;
 	}
 	cout << ans << endl;
}
