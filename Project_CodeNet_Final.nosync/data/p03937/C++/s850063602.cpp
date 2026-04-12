#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20;
int n, m, dp[N][N];
char str[N][N];

int main() {
    scanf("%d%d", &n, &m);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
        for (int j = 1; j <= m; j++)
            tot += (str[i][j] == '#');
    }
    memset(dp, 0, sizeof(dp));
    if (str[n][m] == '#') dp[n][m] = 1;
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            if (str[i][j] == '.') continue;
            dp[i][j] = 1;
            dp[i][j] += max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    printf("%s\n", dp[1][1] == tot ? "Possible" : "Impossible");
    return 0;
}
