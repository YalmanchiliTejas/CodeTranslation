#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> f(h);
    rep (i, h)
        cin >> f[i];

    vector<bool> hDel(h, false);
    vector<bool> wDel(w, false);
    rep (i, h)
    {
        bool ok = true;
        rep (j, w)
        {
            if (f[i][j] == '#')
            {
                ok = false;
                break;
            }
        }
        if (ok)
            hDel[i] = true;
    }
    rep (i, w)
    {
        bool ok = true;
        rep (j, h)
        {
            if (f[j][i] == '#')
            {
                ok = false;
                break;
            }
        }
        if (ok)
            wDel[i] = true;
    }

    rep (i, h)
    {
        if (hDel[i] == true)
            continue;
        rep (j, w)
        {
            if (wDel[j] == true)
                continue;
            cout << f[i][j];
        }
        cout << endl;
    }

    return 0;
}