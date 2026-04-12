#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;

int a[N];
LL f[N][2][3];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    LL ans = -1e18;
    if (n % 2 == 0) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 2; k++) {
                f[0][j][k] = -1e18;
            }
        }
        f[0][0][1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            f[i][0][1] = f[i - 1][1][1];
            f[i][0][0] = max(f[i - 1][1][0], f[i - 1][0][1]);
            f[i][1][1] = f[i - 1][0][1] + a[i];
            f[i][1][0] = f[i - 1][0][0] + a[i];
        }
        ans = f[n + 1][0][0];
    } else {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                f[0][j][k] = -1e18;
            }
        }
        f[0][0][2] = 0;
        for (int i = 1; i <= n + 1; i++) {
            f[i][0][2] = f[i - 1][1][2];
            f[i][0][1] = max(f[i - 1][1][1], f[i - 1][0][2]);
            f[i][0][0] = max(f[i - 1][1][0], f[i - 1][0][1]);
            f[i][1][2] = f[i - 1][0][2] + a[i];
            f[i][1][1] = f[i - 1][0][1] + a[i];
            f[i][1][0] = f[i - 1][0][0] + a[i];
        }
        ans = f[n + 1][0][0];
    }

    cout << ans << endl;
    return 0;
}
