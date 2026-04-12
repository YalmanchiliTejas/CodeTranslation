#include <bits/stdc++.h>

using namespace std;

int CountPath(const vector<vector<int>> &g) {
    const int s = 0;
    const int n = g.size();
    int cnt = 0;
    vector<int> idx(n - 1);

    for (int i = 0; i < n - 1; ++i)
        idx[i] = i + 1;

    do {
        bool can_reach = true;
        int cur = s;

        for (int i = 0; i < n - 1; ++i) {
            bool can_nxt = false;
            for (auto u : g[cur])
                if (u == idx[i]) {
                    can_nxt = true;
                    break;
                }

            if (!can_nxt) {
                can_reach = false;
                break;
            }

            cur = idx[i];
        }

        if (can_reach) ++cnt;

    } while (next_permutation(idx.begin(), idx.end()));

    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a - 1].emplace_back(b - 1);
        g[b - 1].emplace_back(a - 1);
    }

    cout << CountPath(g) << endl;

    return 0;
}
