#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define y_n(ans) cout<<(ans?"Yes":"No")<<endl;

const long long mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    vector<long long> csum(n-1);
    csum[n-2] = a[n-1];
    for (int i = n-3; i >= 0; --i) {
        csum[i] = csum[i+1] + a[i+1];
    }
    long long ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ans += csum[i]%mod * a[i]%mod;
        ans %= mod;
    }
    cout << ans << endl;
}