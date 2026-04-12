#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;
    // レベル L バーガーの層枚数, パティ枚数
    vector<ll> sum(51), p(51);
    sum[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        sum[i] = sum[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    ll res = 0;
    int level = n;
    while (x)
    {
        if (level == 1)
        {
            if (x == 5)
                res += 3;
            else if (x != 1)
                res += x - 1;
            break;
        }
        if (x >= sum[level] - 1)
        {
            res += p[level - 1] * 2 + 1;
            break;
        }
        if (x >= sum[level - 1] + 2)
        {
            res += p[level - 1];
            x -= sum[level - 1];
            res++;
            x -= 2;
            level--;
            continue;
        }
        if (x == sum[level - 1] + 1)
        {
            res += p[level - 1];
            break;
        }
        x--;
        level--;
    }
    cout << res << endl;
}
