#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ans = (ans + sum * x % MOD) % MOD;
        sum = (sum + x) % MOD;
    }
    cout << ans << endl;
}