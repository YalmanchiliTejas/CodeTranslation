#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    const long long mod = 1e9+7;
    int n;
    cin >> n;
    vector< long long > a(n+1, 0), b(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) b[i] = (b[i-1] + a[i]) % mod;
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans += a[i] * (b[n]-b[i]+mod) % mod;
    }
    cout << ans%mod << endl;
}
