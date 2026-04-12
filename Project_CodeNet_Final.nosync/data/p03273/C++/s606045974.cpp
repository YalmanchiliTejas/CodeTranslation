#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];
    vector<bool> rmrow(h, false), rmcol(w, false);
    for (int i = 0; i < h; ++i)
    {
        bool ok = true;
        for (int j = 0; j < w; ++j)
        {
            if(s[i][j] != '.')
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            rmrow[i] = true;
        }
    }

    for (int j = 0; j < w; ++j)
    {
        bool ok = true;
        for (int i = 0; i < h; ++i)
        {
            if(s[i][j] != '.')
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            rmcol[j] = true;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        bool skip = false;
        for (int j = 0; j < w; ++j)
        {
            if (rmrow[i] || rmcol[j])
            {
                if (rmrow[i]) skip = true;
                continue;
            }
            else
            {
                cout << s[i][j];
            }
        }
        if (skip) continue;
        cout << '\n';
    }
    return 0;
}
