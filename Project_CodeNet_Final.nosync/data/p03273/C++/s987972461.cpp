#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w, 0));
    vector<vector<bool>> tb(h, vector<bool>(w, true));
    repi(i, h, 0)
    {
        repi(j, w, 0)
        {
            cin >> a[i][j];
        }
    }
    bool ok = true;
    while (ok)
    {
        ok = false;
        repi(i, h, 0)
        {
            int cnt = 0;
            int tbcnt = 0;
            repi(j, w, 0)
            {

                if (!tb[i][j])
                    tbcnt++;
                else if (a[i][j] == '.')
                    cnt++;
            }
            if (cnt + tbcnt == w && tbcnt < w)
            {
                ok = true;
                repi(j, w, 0)
                {
                    tb[i][j] = false;
                }
            }
        }

        repi(i, w, 0)
        {
            int cnt = 0;
            int tbcnt = 0;
            repi(j, h, 0)
            {
                if (!tb[j][i])
                    tbcnt++;
                else if (a[j][i] == '.')
                    cnt++;
            }
            if (cnt + tbcnt == h && tbcnt < h)
            {
                ok = true;
                repi(j, h, 0)
                {
                    tb[j][i] = false;
                }
            }
        }
    }
    repi(i, h, 0)
    {
        int cnt = 0;
        repi(j, w, 0)
        {
            if (tb[i][j])
            {
                cout << a[i][j];
                cnt++;
            }
        }
        if (cnt)
        {
            cout << "\n";
        }
    }
    cout << "\n";
    return 0;
}