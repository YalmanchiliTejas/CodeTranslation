#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<ll> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + a[i];
        s[i] %= MOD;
    }
    
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += s[i] * a[i + 1];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}
