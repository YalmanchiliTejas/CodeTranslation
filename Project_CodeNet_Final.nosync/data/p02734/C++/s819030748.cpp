#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353, N = 3005;

int n, s;
int a[N];
int f[N];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j > a[i]; j--) f[j] = (f[j] + f[j - a[i]]) % mod;
        f[a[i]] = (f[a[i]] + i) % mod;
        ans = (ans + (ll)f[s] * (n - i + 1) % mod) % mod;
        f[s] = 0;
    }
    printf("%d\n", ans);
    return 0; 
}