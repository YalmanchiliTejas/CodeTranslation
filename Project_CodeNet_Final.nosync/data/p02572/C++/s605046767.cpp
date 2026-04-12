#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    const ll p = 1000000007;
    ll ans = 0;
    ll b = a.at(0)%p;
    for (int i = 1; i < n; i++) {
        ans += (a.at(i)%p) * (b%p);
        ans %= p;
        b += a.at(i) % p;
        b %= p;
    }
    cout << ans << endl;
    return 0;
}