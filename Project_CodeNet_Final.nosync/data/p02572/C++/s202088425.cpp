#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
const ll mod = 1000000007;
ll n;
int main(){
    cin >> n;
    ll sum[N] = {0};
    ll ans = 0;
    vector<ll> a(n + 10);

    for(int i = 1;i<=n;i++){
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i]);
    }

    for(int i = 1;i<=n-1;i++){
        ans += (a[i] * ((sum[n] - sum[i]) % mod));
        ans %= mod;
    }
    cout << ans % mod << endl;

    return 0;
}