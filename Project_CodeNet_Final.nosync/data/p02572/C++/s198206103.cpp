#include <bits/stdc++.h>

#define mo 1000000007
using namespace std;

int n, a[200005], pre[200005], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pre[i] = (pre[i - 1] + a[i]) % mo;
        ans = (ans + (long long) pre[i - 1] * a[i]) % mo;
    }
    printf("%d", ans);
    return 0;
}