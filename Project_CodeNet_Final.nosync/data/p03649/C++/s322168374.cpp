#include <bits/stdc++.h>

#define ll long long
using namespace std;
int n;
ll a[55], b[55];
ll tmp, ans;
bool ok;

int main() {
    //freopen("../in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    while (!ok) {
        ok = 1;
        tmp = 0;
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] / n;
            tmp += b[i];
            a[i] -= b[i] * n;
        }
        for (int i = 0; i < n; ++i) {
            a[i] += tmp - b[i];
            if (a[i] >= n) ok = 0;
        }
        ans += tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
