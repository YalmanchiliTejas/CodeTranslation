#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> G[8];

int dfs(int s, int sum, vector<bool> v) {
    v[s] = true;
    int cnt = 0;
    sum++;
    if (sum == N) {
        return 1;
    }
    for (int i = 0; i < G[s].size(); i++) {
        int next = G[s][i];
        if (!v[next]) cnt += dfs(next, sum, v);
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> v(N, false);
    cout << dfs(0, 0, v) << endl;
}