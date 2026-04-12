#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
const ll INF = 1e18;

int N;
int a[MAX];
ll f[2][MAX][2];//选到第i个数, 已经选了j个, 当前选了1，没选0的最大值


int main() {
#ifdef ACM_LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    memset(f, -0x3f, sizeof(f));
    for (int i = 0; i <= N; i++) f[0][i][0] = 0;
    for (int i = 1; i <= N; i++) {
        int now = i % 2, pre = now ^ 1;
        for (int j = max(0, i / 2 - 10); j <= i / 2; j++) {
            f[now][j + 1][1] = -INF;
            f[now][j][0] = -INF;
        }
        for (int j = max(0, i / 2 - 10); j <= i / 2; j++) {
            f[now][j + 1][1] = max(f[now][j + 1][1], f[pre][j][0] + a[i]);
            f[now][j][0] = max(f[now][j][0], max(f[pre][j][0], f[pre][j][1]));
        }
    }
    printf("%lld\n", max(f[N % 2][N / 2][0], f[N % 2][N / 2][1]));


    return 0;
}
