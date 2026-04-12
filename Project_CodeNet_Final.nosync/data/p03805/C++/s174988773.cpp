#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

typedef long long ll;

using namespace std;

int ans = 0;
int N = 0;
int M = 0;
bool visited[9];
vector<int> adj[9];

void dfs(int v) {
    bool f = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            f = false;
            break;
        }
    }

    if (f) {
        ans++;
        return;
    }

    for (auto u : adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            dfs(u);
            visited[u] = false;
        }
    }

    return;
}


int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int ai, bi; cin >> ai >> bi;
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
    }

    visited[1] = true;
    dfs(1);
    cout << ans << endl;
}
