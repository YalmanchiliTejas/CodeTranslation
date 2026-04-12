#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m, nmax = 8;
int graph[8][8] = {0};

int dfs(int now, bool* visited) {
    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) all_visited = false;
    }

    if (all_visited) return 1;

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i] and graph[now][i]) {
            visited[i] = true;
            ret += dfs(i, visited);
            visited[i] = false;
        }
    }
    return ret;
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = 1;
    }

    bool visited[n] = {false};
    visited[0] = true;

    cout << dfs(0, visited) << endl;

    return 0;
}

