#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sum = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ans += sum * x;
        ans %= 1000000007;
        sum += x;
        sum %= 1000000007;
    }
    cout << ans;
    return 0;
}