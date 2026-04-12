#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
using namespace std;


int ans = 0;
int N, M;

void dfs(vector<int> sinro, vector<vector<int>> edge, vector<bool> reached, int node) {
    bool has_next = false;
    reached[node] = true;

    rep(i, edge[node].size()) {
        int next_node = edge[node][i];

        // next_nodeにまだ到達していなければ
        if (!reached[next_node]) {
            dfs(sinro, edge, reached, next_node);
            has_next = true;
        } else {
            continue;
        }
    }

    // next nodeがなかった場合、
    if (!has_next) {
        bool all_reached = true;

        //全てのnodeを探索
        rep (i, N) {
            all_reached = all_reached && reached[i];
        }

        // 全てのnodeを通過していた場合
        if (all_reached) {
            ans += 1;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> edge(N);
    vector<bool> reached(N, false);
    rep(i, M){
        int ai, bi;
        cin >> ai >> bi;
        edge[ai-1].push_back(bi-1);
        edge[bi-1].push_back(ai-1);
    }

    int node = 0;
    vector<int> sinro;

    sinro.push_back(node);
    dfs(sinro, edge, reached, node);
    
    cout << ans << endl;

    return 0;
}