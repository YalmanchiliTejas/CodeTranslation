#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using uint64 = unsigned long long;

const int64 MOD = 1e9 + 7;

constexpr int MAX_N = 100;
int64 h[MAX_N];

int64 powMod(int64 a, int64 n)
{
    int64 res = 1;
    a = a % MOD;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int times = 0;

pair<int64, int64> counting(int l, int r, int offset)
{
    if (l == r)
    {
        return {1, 0};
    }

    int64 cnt1 = 1, cnt2 = 1,
          minHeight = *min_element(h + l, h + r);
    
    int rectL = l, x = 0;
    for (int i = l; i < r; i++)
    {
        if (h[i] == minHeight)
        {
            auto cres = counting(rectL, i, minHeight);

            cnt1 = (cnt1 * cres.first) % MOD;
            cnt2 = (cnt2 * (cres.first + cres.second)) % MOD;

            rectL = i + 1;
            x++;    // 上に乗っかっていない
        }
    }
    auto cres = counting(rectL, r, minHeight);

    cnt1 = (cnt1 * cres.first) % MOD;
    cnt2 = (cnt2 * (cres.first + cres.second)) % MOD;

    int height = minHeight - offset;
    cnt2 = (powMod(2, x) * cnt2 % MOD + cnt1 * ((powMod(2, height) + MOD - 2) % MOD)) % MOD;
    cnt1 = powMod(2, height) * cnt1 % MOD;

    return {cnt1, cnt2};
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    cout << counting(0, N, 0).second << endl;

    return 0;
}
