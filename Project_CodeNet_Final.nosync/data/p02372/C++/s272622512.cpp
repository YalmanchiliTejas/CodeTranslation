#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    using ii = pair<int, int>;
    vector<vector<ii>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        adj[s].push_back(ii(t, w));
        adj[t].push_back(ii(s, w));
    }

    vi dp(n);
    function<void(int, int)> kek = [&](int v, int p) {
        int nax = 0;
        for (ii s: adj[v]) {
            if (s.first != p) {
                kek(s.first, v);
                nax = max(nax, (int)dp[s.first] + s.second);
            }
        }
        dp[v] = nax;
    };
    kek(0, -1);
    // for (int i = 0; i < n; i++) {
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // }
    vi dp2(n);
    function<void(int, int)> kek2 = [&](int v, int p) {
        vector<ii> tmp = {ii(dp2[v], p)};
        for (ii s: adj[v]) {
            if (s.first != p) {
                tmp.push_back(ii(dp[s.first] + s.second, s.first));
            }
        }
        sort(tmp.begin(), tmp.end(), greater<>());
        for (ii s: adj[v]) {
            if (s.first != p) {
                dp2[s.first] = tmp[tmp[0].second == s.first].first + s.second;
                kek2(s.first, v);
            }
        }
    };
    kek2(0, -1);
    // for (int i = 0; i < n; i++) {
    //     cout << "dp2[" << i << "] = " << dp2[i] << endl;
    // }
    for (int i = 0; i < n; i++) {
        cout << max(dp[i], dp2[i]) << endl;
    }
}
