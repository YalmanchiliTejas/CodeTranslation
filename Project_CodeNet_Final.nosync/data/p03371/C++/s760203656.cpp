#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using P1 = pair<int, P>;
#define FOR(t, a, b) for (int t = (a); t < (b); ++t)
#define REP(t, n) FOR(t, 0, n)

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int many = max(x, y);
    int ans = INT_MAX;

    int loop = 0;
    for (int i = 2 * many; i >= 0; i -= 2)
    {
        int tempans = 0;
        tempans += c * i;
        if (x > y)
        {
            tempans += a * loop;
            if (i / 2 < y)
            {
                tempans += b * (y - i / 2);
            }
        }
        else
        {
            tempans += b * loop;
            if (i / 2 < x)
            {
                tempans += a * (x - i / 2);
            }
        }
        if (ans > tempans)
        {
            ans = tempans;
        }
        loop++;
    }
    cout << ans << endl;

    return 0;
}
