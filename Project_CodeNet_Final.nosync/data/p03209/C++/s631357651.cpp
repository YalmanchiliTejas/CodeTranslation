#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    ll N, X;
    cin >> N >> X;

    pair<ll, ll> c[N + 1];
    c[0] = make_pair(1, 0);
    FOR(i, 1, N + 1) {
        ll p = 2 * c[i - 1].first + 1;
        ll b = 2 * c[i - 1].second + 2;
        c[i] = make_pair(p, b);
    }

    ll ans = 0;
    ll cur = N;
    ll res = X;
    while (cur >= 0) {
        if (cur == 0) {
            ans += res;
            break;
        }
        if (res == 0) break;
        if (res == 1) break;
        if (res == c[cur].first + c[cur].second) {
            ans += c[cur].first;
            break;
        }
        if (res == 1 + c[cur - 1].first + c[cur - 1].second + 1) {
            ans = ans + c[cur - 1].first + 1;
            break;
        }
        if (res < 1 + c[cur - 1].first + c[cur - 1].second + 1) {
            res = res - 1;
            cur--;
        }
        else {
            ans = ans + c[cur - 1].first + 1;
            res = res - 1 - c[cur - 1].first - c[cur - 1].second - 1;
            cur--;
        }
    }

    cout << ans << endl;
    return 0;
}
