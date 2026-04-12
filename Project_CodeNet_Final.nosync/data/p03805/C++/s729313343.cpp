#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll = long long;
const int INF = 999999999;

int N, M;
vector<vector<int>> G;
vector<int> visited;
int ans;
int n_visited;

void dfs(int now) {
    visited[now] = 1;
    n_visited++;
    if (n_visited == N) ans++;
    for (int i = 0; i < G[now].size(); ++i) {
        int next = G[now][i];
        if(!visited[next]) dfs(next);
    }
    visited[now] = 0;
    n_visited--;
}

int main() {
    cin >> N >> M;

    G = vector<vector<int>>(N, vector<int>(N));
    visited = vector<int>(N, 0);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;

}