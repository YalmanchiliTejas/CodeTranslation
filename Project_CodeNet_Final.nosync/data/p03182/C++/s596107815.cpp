#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long i64;
const int NMAX = 200010;
i64 lazy[4 * NMAX], aint[4 * NMAX];
int l, r;
i64 val;
int n;

void update(int nod = 1, int st = 0, int dr = n)
{
//    for (int i = l; i <= r; i++)
//        aint[i] += val;
//    return;
    if (st > r || dr < l)
        return;
    if (l <= st && r >= dr) {
        lazy[nod] += val;
        return;
    }
    update(2 * nod, st, (st + dr) / 2);
    update(2 * nod + 1, (st + dr) / 2 + 1, dr);
    aint[nod] = max(aint[2 * nod] + lazy[2 * nod], aint[2 * nod + 1] + lazy[2 * nod + 1]);
}

i64 query(int nod = 1, int st = 0, int dr = n)
{
//    i64 ans = -1e9;
//    for (int i = l; i <= r; i++)
//        ans = max(ans, aint[i]);
//    return ans;
    if (st > r || dr < l)
        return -1e18;
    if (l <= st && r >= dr)
        return aint[nod] + lazy[nod];
    return lazy[nod] + max(query(2 * nod, st, (st + dr) / 2), query(2 * nod + 1, (st + dr) / 2 + 1, dr));
}

vector <pair <int, int>> segments[NMAX];
i64 dp[NMAX];

int main()
{
    int m, a, b, c;
    scanf("%d%d", &n, &m);

    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        segments[a].push_back({ a - 1, c });
        segments[b + 1].push_back({ a - 1, -c });
    }

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        /// adaug tot ce se termina pana pe i
        for (auto j : segments[i]) {
            l = 0, r = j.first, val = j.second;
//            cout << "Updating segment " << l << ' ' << r << " with " << val << '\n';
            update();
        }

        l = 0, r = i - 1;
        dp[i] = query();
//        cout << "DP for " << i << ": " << dp[i] << '\n';
        ans = max(ans, dp[i]);

        l = i, r = i, val = dp[i];
        update();
    }

    cout << ans << '\n';
    return 0;
}
