#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
ll a[maxn], sum[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= mod;
    }
    ll ans = 0;

    for(int i = 1;i <= n;i++){
        ans += a[i] % mod * sum[i - 1] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
