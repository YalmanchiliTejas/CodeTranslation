#include <bits/stdc++.h>
using namespace std;

/* メモリ食い過ぎ注意 */
#define int long long

typedef long long ll;

/* define const */
const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;
/* end defineing */

signed main()
{
    int h, w;
    int a[100][100];
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            a[i][j] = (s)[j];
        }
    }

    set<int> hv;
    set<int> wv;
    for (int i = 0; i < h; i++)
    {
        bool f = true;
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] != '.')
                f = false;
        }
        if (f)
        {
            // cout << "a" << endl;
            hv.insert(i);
        }
    }

    for (int i = 0; i < w; i++)
    {
        bool f = true;
        for (int j = 0; j < h; j++)
        {
            if (a[j][i] != '.')
                f = false;
        }
        if (f)
        {
            // cout << "b" << endl;
            wv.insert(i);
        }
    }
    /*
    for (auto it = hv.begin(); it != hv.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it = wv.begin(); it != wv.end(); it++)
        cout << *it << " ";
    cout << endl;
*/
    for (int i = 0; i < h; i++)
    {
        if (hv.find(i) != hv.end())
            continue;
        for (int j = 0; j < w; j++)
        {
            if (wv.find(j) != wv.end())
                continue;
            cout << (char)(a[i][j]);
        }
        cout << endl;
    L:
    {
    }
    }
}
