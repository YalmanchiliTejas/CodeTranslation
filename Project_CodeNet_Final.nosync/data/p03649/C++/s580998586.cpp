#include <bits/stdc++.h>
using namespace std;
long long a[100];
int main() {
    int n, mi, ma;
    long long ans = 0, sum, change;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum <= 500000) {
        while (true) {
            ma = 0;
            for (int i = 1; i < n; i++) {
                if (a[ma] < a[i]) ma = i;
            }
            if (a[ma] < n) break;
            a[ma] -= n;
            for (int i = 0; i < n; i++) {
                if (i == ma) continue;
                a[i]++;
            }
            ans++;
        }
        printf("%lld\n", ans);
        return 0;
    }
    while (true) {
        mi = ma = 0;
        for (int i = 1; i < n; i++) {
            if (a[ma] < a[i]) ma = i;
            if (a[mi] > a[i]) mi = i;
        }
        if (a[ma] - a[mi] <= 1000) break;
        //printf("%lld %lld\n", a[ma], a[mi]);
        change = (a[ma] - a[mi]) / (n + 1);
        a[ma] -= change * n;
        for (int i = 0; i < n; i++) {
            if (i == ma) continue;
            a[i] += change;
        }
        ans += change;
        mi = 0;
        for (int i = 1; i < n; i++) {
            if (a[mi] > a[i]) mi = i;
        }
        change = (a[mi] - n);
        ans += change * n;
        for (int i = 0; i < n; i++) a[i] -= change;
    }
    while (true) {
        ma = 0;
        for (int i = 1; i < n; i++) {
            if (a[ma] < a[i]) ma = i;
        }
        if (a[ma] < n) break;
        a[ma] -= n;
        for (int i = 0; i < n; i++) {
            if (i == ma) continue;
            a[i]++;
        }
        ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
