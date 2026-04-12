#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector< vector<bool> > G(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a][b] = true;
        G[b][a] = true;
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    int odp = 0;
    do
    {
        if (p[0] == 0)
        {
            bool db = true;
            for (int i = 0; i < n - 1; ++i)
                if (!G[p[i]][p[i + 1]])
                    db = false;
            if (db)
                ++odp;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << odp;
    return 0;
}
