#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef  long long ll;
ll a[maxn],sum[maxn];
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= mod;
    }
    ll ans = 0;
    for(int i = 2;i <= n;i++){
        ans = (ans + a[i] * sum[i-1]) % mod;
    }
    cout << ans % mod<< endl;
    return 0;
}