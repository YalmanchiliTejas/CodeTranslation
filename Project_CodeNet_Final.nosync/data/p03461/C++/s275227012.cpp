#include <cstdio>
#include <algorithm>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int N = 110;

int n, m, d[N][N], f[N][N], dd[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &d[i][j]);
    FOR(i, 0, 100) FOR(j, 0, 100) FOR(ii, 1, n) FOR(jj, 1, m)
        f[i][j] = max(f[i][j], d[ii][jj] - i * ii - j * jj);
    FOR(ii, 1, n) FOR(jj, 1, m)
    {
        dd[ii][jj] = 1e9;
        FOR(i, 0, 100) FOR(j, 0, 100)
            dd[ii][jj] = min(dd[ii][jj], i * ii + j * jj + f[i][j]);
        if (dd[ii][jj] != d[ii][jj]) {puts("Impossible"); return 0;}
    }
    puts("Possible"); puts("202 10401");
    FOR(i, 1, 100) printf("%d %d X\n", i, i + 1);
    FOR(i, 102, 201) printf("%d %d Y\n", i, i + 1);
    FOR(i, 0, 100) FOR(j, 0, 100) printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
    puts("1 202");
    return 0;
}
