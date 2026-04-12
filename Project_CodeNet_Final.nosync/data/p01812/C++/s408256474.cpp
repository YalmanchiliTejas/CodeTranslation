#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

constexpr int INF = 1e9+7;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> D(M);
    vector<int> idx(N, -1);
    for(int i=0; i<M; ++i) {
        cin >> D[i];
        D[i]--;
        idx[D[i]] = i;
    }
    vector<vector<int>> v(N, vector<int>(K));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<K; ++j) {
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    vector<int> dp(1 << M, INF);
    dp[(1 << M) - 1] = 0;
    queue<int> que;
    que.push((1 << M) - 1);
    while(!que.empty()) {
        int now = que.front(); que.pop();
        for(int k=0; k<K; ++k) {
            int next = 0;
            for(int i=0; i<M; ++i) {
                if((now >> i) & 1 && idx[v[D[i]][k]] != -1) {
                    next |= (1 << idx[v[D[i]][k]]);
                }
            }
            if(dp[next] != INF) {
                continue;
            }
            dp[next] = dp[now] + 1;
            que.push(next);
        }
    }
    cout << dp[0] << endl;
}
