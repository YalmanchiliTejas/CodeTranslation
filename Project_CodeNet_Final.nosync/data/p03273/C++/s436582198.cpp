#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1000000
#define int long long
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> P;
signed main()
{
    int h, w;
    cin >> h >> w;
    char table[110][110];
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> table[i][j];
        }
    }
    rep(i, h)
    {
        bool flag = false;
        rep(j, w)
        {
            if (table[i][j] == '#')
                flag = true;
        }
        if (flag == false)
        {
            rep(j, w) table[i][j] = '1';
        }
    }
    rep(j, w)
    {
        bool flag = false;
        rep(i, h)
        {
            if (table[i][j] == '#')
                flag = true;
        }
        if (flag == false)
        {
            rep(i, h) table[i][j] = '1';
        }
    }
    rep(i, h)
    {
        bool flag = false;
        rep(j, w)
        {
            if (table[i][j] != '1')
            {
                cout << table[i][j];
                flag = true;
            }
        }
        if (flag == true)
            cout << endl;
    }
    return 0;
}