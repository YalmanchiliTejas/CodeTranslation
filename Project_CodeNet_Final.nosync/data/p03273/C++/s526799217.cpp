#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int h, w;
    scanf("%d%d", &h, &w);
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> a.at(i).at(j);
        }
    }
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    rep(i, h)
    {
        rep(j, w)
        {
            if (a.at(i).at(j) == '#')
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    rep(i, h)
    {
        if (row[i])
        {
            rep(j, w)
            {
                if (col[j])
                {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}