#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int INF = (int)1e9 + 7;
using ll = long long;

template<class T>
T knapsack(int N, int W, vector<T> v, vector<int> w) {
    vector<vector<T>> dp(N + 1, vector<T>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    return dp[N][W];
}

struct Town {
    int x = 0, y = 0;
    unordered_map<string, ll> items;
};

inline int dist(Town& a, Town b = Town()) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int N, M, W, T; cin >> N >> M >> W >> T;
    vector<string> i2s(M);
    unordered_map<string, int> s2w, s2p;
    for (int i = 0; i < M; i++) {
        string s; cin >> s; i2s[i] = s;
        cin >> s2w[s] >> s2p[s];
    }
    vector<Town> towns(N);
    for (int t = 0; t < N; t++) {
        int n; cin >> n >> towns[t].x >> towns[t].y;
        while (n--) {
            string s; int q; cin >> s >> q;
            towns[t].items[s] = s2p[s] - q;
        }
    }
    vector<ll> main_v(1 << N, 0); vector<int> main_w(1 << N, INF);
    for (int mask = 1; mask < 1 << N; mask++) {
        vector<int> ids;
        for (int t = 0; t < N; t++) if (mask & (1 << t)) {
            ids.push_back(t);
        }
        vector<ll> sub_v(M); vector<int> sub_w(M);
        for (int i = 0; i < M; i++) {
            sub_w[i] = s2w[i2s[i]];
            for (int t : ids) {
                sub_v[i] = max(sub_v[i], towns[t].items[i2s[i]]);
            }
        }
        main_v[mask] = knapsack(M, W, sub_v, sub_w);
        int& optime = main_w[mask];
        do {
            int tmp = dist(towns[ids.front()]) + dist(towns[ids.back()]);
            for (auto it = ids.begin(); it + 1 < ids.end(); it++) {
                tmp += dist(towns[*it], towns[*(it + 1)]);
            }
            optime = min(optime, tmp);
        } while (next_permutation(ids.begin(), ids.end()));
    }
    cout << knapsack(1 << N, T, main_v, main_w) << endl;
    return 0;
}
