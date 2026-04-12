#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

#define REP(i, s, e) for (ll i = s; i < e; ++i)

using namespace std;
using ll = long long;
using ld = long double;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    vector<int> wi(W);
    vector<int> hi(H);
    REP(y, 0, H)
    {
        string s;
        cin >> s;
        REP(x, 0, W)
        {
            a[y][x] = s[x];
            if (a[y][x] == '#')
            {
                wi[x]++;
                hi[y]++;
            }
        }
    }

    REP(y, 0, H)
    {
        if (hi[y] == 0) continue;
        REP(x, 0, W)
        {
            if (wi[x] == 0) continue;
            cout << a[y][x];
        }
        cout << endl;
    }

    return 0;
}
