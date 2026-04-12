#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const long long mod = 998244353;
long long power(long long a, long long b, long long m = mod) {
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 3000+9;
ll f[N], a[N], pre[N];
int n, s;

signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    // f[0] = 1;
    for(int i = 1; i <= n; i++) {
        // j > a[i]
        f[0]++;
        for(int j = s; j >= a[i]; j--) {
            f[j] += f[j-a[i]];
            if(f[j] >= mod) f[j] -= mod;
        }
        ans = (ans + f[s] * (n-i+1) % mod) % mod;
        f[s] = 0;
    }
    // cout << "brute:" << brute() << " ";
    cout << ans << "\n";

    return 0;
    
}