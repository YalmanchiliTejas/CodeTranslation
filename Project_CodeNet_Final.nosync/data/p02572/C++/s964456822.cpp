#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    vector<ll> b(n-1);
    b[0] = a[0];
    // cout << b[0] << " ";
    rep(i,n-2) {
        b[i+1] = (b[i] + a[i+1]) % 1000000007;
        // cout << b[i+1] << " ";
    }
    // cout << endl;

    int ans = 0;
    rep(i,n-1) {
        ans += a[i+1] * b[i] % 1000000007;
        ans %= 1000000007;
        // cout << a[i+1] << " " << b[i] << " " << ans << endl;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}
