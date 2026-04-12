#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sum=0,p=1000000007;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans=0;
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        ll q=sum % p;
        q *= a[i];
        q %= p;
        ans += q;
        ans %= p;
    }
    cout << ans << endl;

    return 0;
}