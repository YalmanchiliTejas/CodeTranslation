#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum_a = 0;
    ll sum = 0;
    rep(i,n) sum_a += a[i];
    ll b = sum_a;
    rep(i,n-1) {
        b = b - a[i];
        int c = b%1000000007;
        sum += (a[i]*c)%1000000007;;
        sum = sum%1000000007;
        // cout << sum << endl;
    }
    int ans = sum%1000000007;
    // cout << sum_a << endl;
    cout << ans << endl;
    return 0;
}