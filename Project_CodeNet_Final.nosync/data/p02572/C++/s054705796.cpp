#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    ll ans = (sum * sum) % MOD;
    for(int i = 0; i < n; i++) {
        ans -= (a[i] * a[i]) % MOD;
        ans = (ans + MOD) % MOD;
    }
    ans = ans * 500000004;
    cout << ans % MOD << endl;
}