#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) b[i] = a[i];
    
    b[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) b[i] = (a[i] + b[i+1]) % MOD;
    
    ll ans = 0, tmp;
    for (int i=0; i<n-1; i++) {
        tmp = a[i] * b[i+1] % MOD;
        ans = (ans + tmp) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}
