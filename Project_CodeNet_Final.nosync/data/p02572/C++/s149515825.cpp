#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
    int n; cin >> n; int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long int suffix[n]; suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = (suffix[i + 1] + arr[i]) % mod;
    }
    long long int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (1LL * arr[i] * suffix[i + 1]) % mod;
    }
    cout << ans % mod;
    return 0;
}