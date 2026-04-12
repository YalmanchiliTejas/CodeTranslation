#include <bits/stdc++.h>

using namespace std;
#define N 200200
#define MOD 1000000007LL

long long v[N], s[N];
long ans;
int n, i;
int main(){
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> v[i + 1];
        s[i + 1] = (v[i + 1] + s[i]) % MOD;
    }
    ans = 0;
    for (i = 0; i < n; ++i) {
        ans += (v[i + 1] * (s[n] - s[i + 1] + MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
