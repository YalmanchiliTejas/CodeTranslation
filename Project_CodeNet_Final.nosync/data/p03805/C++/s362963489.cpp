#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int g[8][8];
int sol;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = 1;
    }
    int a[8];
    iota(a, a + n, 0);
    do
    {
        bool good = true;
        for (int i = 1; i < n; ++i)
            if (!g[a[i]][a[i - 1]])
                good = false;
        if (good)
            sol++;
    } while (next_permutation(a + 1, a + n));
    cout << sol;
}
// foo