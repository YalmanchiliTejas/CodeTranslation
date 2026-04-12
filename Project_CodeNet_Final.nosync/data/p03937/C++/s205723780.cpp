#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int H, W;
char a[9][9];

int main()
{
    cin >> H >> W;
    int cnt = 0;
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    if (cnt == (H + W - 1))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}
