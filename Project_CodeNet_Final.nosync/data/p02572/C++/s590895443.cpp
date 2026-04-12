#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
ll a[maxn] , pre[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    for (int i = 1 ; i <= n ; i ++) cin >> a[i] , pre[i] = (pre[i - 1] + a[i]) % mod;
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++){
        ans = (ans + a[i] * pre[i - 1] % mod) % mod;
    }
    cout << ans <<endl;
    return 0;
}
