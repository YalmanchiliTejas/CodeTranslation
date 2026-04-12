#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int nmax = 8;
vector<vector<bool>> grahp(nmax, vector<bool>(nmax));
vector<bool> visited(nmax, true);

int dfs(int v, int N, vector<bool> visited) {

    bool all_visited = true;

    rep(i, N) {
        if(visited[i] == false) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;
    rep(i, N) {
        if(grahp[v][i] == false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret+=dfs(i, N, visited);
        visited[i] = false;

    }

    return ret;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    rep(i, M) {
        int x, y;
        cin >> x >> y;
        grahp[x-1][y-1] = grahp[y-1][x-1] = true;
    }

    vector<bool> visited(N, false);

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;

    return 0;

}
