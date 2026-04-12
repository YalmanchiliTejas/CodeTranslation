#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;
const ll mod = 1e9 + 7;

ll n, a[N], sum[N];
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = (sum[i - 1] + a[i]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = sum[n] - sum[i];
        cnt = (cnt + mod) % mod;
        ans = (ans + cnt * a[i] % mod) % mod;
    }
    cout << ans << endl;
   
}