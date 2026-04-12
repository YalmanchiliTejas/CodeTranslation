#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
ll MOD = 1000000007;
int main() {
    ll n;
    cin >> n;
    ll a[n], sum[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
        (i > 0? (sum[i] = sum[i-1] + a[i])%=MOD: sum[i] = a[i]);
    }
    ll sumall = 0;
    for(int i=0; i<n-1; i++) {
        (sumall += (a[i]%MOD * (sum[n-1]-sum[i]+MOD)%MOD) % MOD ) %= MOD;
    }
    cout << sumall;
    return 0;
}
