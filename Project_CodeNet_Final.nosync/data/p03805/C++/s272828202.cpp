#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int edge[10][10];
    cin >> n >> m;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        v[i] = i + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        edge[a - 1][b - 1] = edge[b - 1][a - 1] = 1;
    }
    int ans = 0;
    do
    {
        int p = 0, f = 1;
        for (int i : v)
        {
            if (!edge[p][i])
            {
                f = 0;
                break;
            }
            p = i;
        }
        if (f)
        {
            ++ans;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << "\n";
    return 0;
}
