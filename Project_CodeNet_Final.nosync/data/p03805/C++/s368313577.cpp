#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Es(N, vector<int>());
    for (int m = 0; m!= M; ++m){
        int a, b;
        cin >> a >> b;
        Es[a - 1].push_back(b - 1);
        Es[b - 1].push_back(a - 1);
    }
    vector<vector<int>> dp(1 << N, vector<int>(N, 0));
    vector<pair<int, int>> frontiers;
    frontiers.emplace_back(make_pair(1, 0));
    dp[1][0] = 1;
    for (int depth = 0; depth < N - 1; ++depth){
        vector<pair<int, int>> new_frontiers;
        for (auto p : frontiers){
            auto visited = p.first;
            auto v = p.second;
            auto val = dp[visited][v];
            for (auto u : Es[v]){
                if ((1 << u) & visited) continue;
                auto new_visited = visited | (1 << u);
                if (dp[new_visited][u] == 0){
                    new_frontiers.emplace_back(make_pair(new_visited, u));
                }
                dp[new_visited][u] += val;
            }
        }
        frontiers = new_frontiers;
    }
    int mask_all = (1 << N) - 1;
    cout << accumulate(dp[mask_all].begin(), dp[mask_all].end(), 0) << endl;
    return 0;
}