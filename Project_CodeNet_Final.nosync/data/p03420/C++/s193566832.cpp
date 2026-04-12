#include <bits/stdc++.h>
#define FI(i,a,b) for(int i=(a);i<=(b);++i)
#define FD(i,b,a) for(int i=(b);i>=(a);--i)
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    LL ans = 0;
    FI(b, k + 1, n) {
        int m = n / b;
        ans += 1LL * m * (b - k);
        int x = k + m * b;
        if (x <= n) ans += n - x + 1;
        if (k == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}
