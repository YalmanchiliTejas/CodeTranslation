#include <iostream>
using namespace std;

const long long mod = 1e9+7;
long long a[200005], sum[200005], ans, n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i >= 1; i--)
        sum[i] = (sum[i+1]+a[i])%mod;

    for(int i = 1; i < n; i++) {
        ans += a[i]*sum[i+1];
        ans %= mod;
    }
    cout << ans;
}
