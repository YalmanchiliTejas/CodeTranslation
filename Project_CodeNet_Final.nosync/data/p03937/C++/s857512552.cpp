#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif // ONPC
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                if (mx > j)
                {
                    cout << "Impossible\n";
                    return 0;
                }
                mx = j;
            }
        }
    }
    cout << "Possible\n";
}
