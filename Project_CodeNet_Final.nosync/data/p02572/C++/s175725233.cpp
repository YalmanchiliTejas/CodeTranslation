#include <bits/stdc++.h>

using namespace std;


constexpr int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        sum %= mod;
    }
    long long ans = 0;
    for(int i = 0; i < n ; i++) {
        sum -= a[i];
        if(sum < 0) {
            sum += mod;
        }
        ans += (a[i] * sum);
        ans %= mod;
    }
    ans %= mod;
    cout << ans << "\n";
    return 0;
}