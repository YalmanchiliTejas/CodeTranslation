#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = (ans + (a * 1LL * sum) % mod) % mod;
        sum = (sum + a) % mod;
    }
    cout << ans << endl;
    return 0;
}