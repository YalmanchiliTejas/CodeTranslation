#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    ll ans = n * (ll) n;
    for (int b = 1; b <= n; b++)
    {
        for (int cur = 0; cur <= n; cur += b)
        {
            int en = min(n, cur + b - 1);
            int dist = min(en - cur + 1, k);
            ans -= dist;
        }
    }
    for (int b = 1; b <= n; b++)
    {
        if (0 % b < k) ans++;
    }
    cout << ans << '\n';
}
