#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int N = 100;
int n, m, a[N][N];
char S[N][N];

int main() {
    #ifdef LOCAL
        freopen("Data.inp", "r", stdin);
        freopen("Data.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", S[i] + 1);

    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= m && S[i][j] == '#') {
            a[i][j] = 1;
            j++;
        }
        j--;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 0 && S[i][j] == '#') {
                puts("Impossible");
                return 0;
            }
    puts("Possible");
    return 0;
}
