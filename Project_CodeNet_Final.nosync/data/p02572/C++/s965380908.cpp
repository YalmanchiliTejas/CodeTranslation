#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
    int n; scanf("%d", &n);
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        (sum += a[i]) %= MOD;
    }
 
    ll ans = 0;
    for (int i = 0; i < n; i++){
        sum -= a[i];
        if (sum < 0) sum += MOD;
 
        ans += a[i] * sum;
        ans %= MOD;
    }
	printf("%lld\n", ans);
}