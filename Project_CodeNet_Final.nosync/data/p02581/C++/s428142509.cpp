#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define REP(i, start, end) for (ll i = start, i##Len = (end); i < i##Len; ++i)
#define REPR(i, start, end) for (ll i = start, i##Len = (end); i > i##Len; --i)
using ll = long long;
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vector<int> a(N * 3);
    REP(i, 0, N * 3)
    {
        cin >> a[i];
        a[i]--;
    }

    int add = 0, minf = -1e9;

    vector<vector<int>> dp(N, vector<int>(N, minf));
    vector<int> max_a(N, minf), next_max_a(N, minf);
    int max_v = 0, next_max_v = minf;
    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    max_a[a[0]] = 0;
    max_a[a[1]] = 0;

    auto update = [&](int x, int y, int val) {
        dp[x][y] = max({dp[x][y], dp[y][x], val});
        dp[y][x] = max({dp[x][y], dp[y][x], val});
        next_max_a[x] = max(next_max_a[x], dp[x][y]);
        next_max_a[y] = max(next_max_a[y], dp[x][y]);
        next_max_v = max(next_max_v, dp[x][y]);
    };

    for (int i = 2; i < N * 3 - 1; i += 3)
    {
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
        {
            ++add;
            continue;
        }

        vector<int> card = {a[i], a[i + 1], a[i + 2]};
        sort(card.begin(), card.end());
        vector<tuple<int, int, int>> query;

        REP(_, 0, 3)
        {
            query.emplace_back(card[1], card[2], dp[card[0]][card[0]] + 1);
            if (card[0] == card[1])
                REP(j, 0, N)
            query.emplace_back(j, card[2], max(dp[card[0]][j], dp[j][card[0]]) + 1);
            card.emplace_back(card[0]);
            card.erase(card.begin());
        }

        REP(_, 0, 3)
        {
            REP(j, 0, N)
            {
                update(j, card[0], max_a[j]);
            }
            update(card[0], card[1], max_v);
            update(card[0], card[2], max_v);

            card.emplace_back(card[0]);
            card.erase(card.begin());
        }

        for (auto &[x, y, z] : query)
        {
            update(x, y, z);
        }

        swap(max_a, next_max_a);
        max_v = next_max_v;
    }

    dp[a.back()][a.back()]++;
    int ans = 0;
    REP(i, 0, N)
    REP(j, 0, N)
    {
        ans = max(ans, dp[i][j]);
    }

    cout << ans + add << endl;
}