#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

using namespace std;

const ll mod = 1e9 + 7;

int main() {
    ios
    int n;
    cin >> n;
    ll ans = 0, a[n], sum = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        ans += sum * a[i];
        ans %= mod;
        sum += a[i];
        sum %= mod;
    }
    cout << ans;
    return 0;
}
