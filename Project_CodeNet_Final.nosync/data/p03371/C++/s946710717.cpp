
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    //! all Pizza A or B
    int ans = a * x + b * y;

    //! all Pizza AB
    int tmp = c * 2 * max(x, y);
    ans = min(ans, tmp);

    //! all Pizza A from Pizza AB the rest from Pizza B
    tmp = c * 2 * x;
    if (x < y) {
        tmp += b * (y-x);
    }
    ans = min(ans, tmp);

    //! all Pizza B from Pizza AB the rest from Pizza A
    tmp = c * 2 * y;
    if (y < x) {
        tmp += a * (x-y);
    }
    ans = min(ans, tmp);

    cout << ans << endl;

    return 0;
}
