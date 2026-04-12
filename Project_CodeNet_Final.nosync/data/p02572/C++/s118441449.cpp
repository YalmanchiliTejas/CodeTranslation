#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= mod;
    }
    vector<int> suf(n);
    suf[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        suf[i] = (suf[i+1] + a[i])%mod;

    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        ans = (ans + (a[i]*1LL*suf[i+1])%mod )%mod;
    }
    cout << ans << endl;


    return 0;
}

