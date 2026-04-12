#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll n,k;
ll ans = 0;
cin >> n >> k;
for (ll b = 1; b <= n;b++){
    ans += max(0LL, b - k) * (n / b);
    ans += max(0LL, n % b - k + 1);
}
if (k == 0) ans -= n;
cout << ans << endl;
}
