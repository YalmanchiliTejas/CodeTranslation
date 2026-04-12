// F
// DeP
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 3e3 + 5, P = 998244353;

int n, S;
int A[MAXN], f[MAXN][MAXN][3];

int main() {
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; ++i) scanf("%d", A + i);
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= S; ++j) {
            int d = f[i-1][j][0];
            f[i][j][0] = (f[i][j][0] + d) % P;
            d = (d + f[i-1][j][1]) % P;
            f[i][j][1] = (f[i][j][1] + d) % P;
            d = (d + f[i-1][j][2]) % P;
            f[i][j][2] = (f[i][j][2] + d) % P;
            if (j >= A[i]) {
                d = (f[i-1][j - A[i]][0] + f[i-1][j - A[i]][1]) % P;
                f[i][j][1] = (f[i][j][1] + d) % P, f[i][j][2] = (f[i][j][2] + d) % P;
            }
        }
    printf("%d\n", f[n][S][2]);
    return 0;
}