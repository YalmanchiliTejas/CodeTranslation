#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            if (s[j] == '#')
                cnt++;
        }
    }

    if (cnt == h + w - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}