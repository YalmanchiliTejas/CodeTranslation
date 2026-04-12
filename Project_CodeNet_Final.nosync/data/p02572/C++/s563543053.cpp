#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long int ans = 0, mod = 1000000007; 
    cin >> n;
    long long int a[n], b[n+1];
    for(int i = 0; i < n; ++i) cin >> a[i];
    b[n] = 0;
    for(int i = n-1; i >= 0; --i) {
        b[i] = (b[i+1] + a[i])%mod;
    }

    for(int i = 0; i < n-1; ++i) {
        ans = (ans + (a[i]*b[i+1])%mod)%mod;
    }
    cout << ans << '\n';
}
