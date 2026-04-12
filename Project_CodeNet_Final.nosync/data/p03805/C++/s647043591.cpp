#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INFLL = 1LL << 60;
const long long MOD = 1e9 + 7;

bool graph[8][8];

int dfs(int v, int N, bool visited[8]) {
    bool all = 1;
    rep(i, N) if(!visited[i]) all = 0;
    if(all) return 1;
    int ret = 0;
    rep(i, N) {
        if(!graph[v][i]) continue;
        if(visited[i]) continue;
        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, 8) rep(j, 8) graph[i][j] = 0;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = 1;
    }
    bool visited[8] = {0};
    visited[0] = 1;
    cout << dfs(0, N, visited) << endl;
}