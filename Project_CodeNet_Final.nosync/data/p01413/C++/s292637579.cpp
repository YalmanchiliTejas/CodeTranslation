#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

int main() {
    int n, m, w, t;
    cin >> n >> m >> w >> t;
    unordered_map<string, int> dic;
    vector<int> v(m);
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s >> v[i] >> p[i];
        dic.insert({s, i});
    }
    vector<P> places(n);
    vector<vector<int>> prices(n, vector<int>(m, 10010));
    for (int i = 0; i < n; ++i) {
        int l, x, y;
        cin >> l >> x >> y;
        places[i] = P(x, y);
        for (int j = 0; j < l; ++j) {
            string s;
            int q;
            cin >> s >> q;
            prices[i][dic[s]] = q;
        }
    }
    vector<long long> dp(t + 1);
    for (int i = 1; i < (1 << n); ++i) {
        vector<int> towns;
        int sz = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                towns.push_back(j);
                ++sz;
            }
        }
        int d = M;
        do {
            int dis = abs(places[towns[0]].first) + abs(places[towns[0]].second) + abs(places[towns[sz - 1]].first) + abs(places[towns[sz - 1]].second);
            for (int i = 0; i < sz - 1; ++i)
                dis += abs(places[towns[i + 1]].first - places[towns[i]].first) + abs(places[towns[i + 1]].second - places[towns[i]].second);

            d = min(d, dis);
        } while (next_permutation(towns.begin(), towns.end()));

        if (d > t) continue;

        vector<int> benef(m);
        for (auto& j : towns)
            for (int k = 0; k < m; ++k)
                benef[k] = max(benef[k], p[k] - prices[j][k]);

        vector<int> dp2(w + 1);
        for (int j = 0; j < m; ++j)
            for (int k = v[j]; k <= w; ++k)
                dp2[k] = max(dp2[k], dp2[k - v[j]] + benef[j]);

        dp[d] = max(dp[d], (long long)dp2[w]);
    }
    vector<int> inis;
    for (int i = 0; i <= t; ++i)
        if (dp[i] > 0)
            inis.push_back(i);

    for (int i = 1; i <= t; ++i) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (auto& j : inis) {
            if (j >= i) continue;
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
        }
    }
    cout << dp[t] << "\n";
    return 0;
}

