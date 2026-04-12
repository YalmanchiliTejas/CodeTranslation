#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
                cnt++;
        }
    }
    if (cnt == h + w - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}