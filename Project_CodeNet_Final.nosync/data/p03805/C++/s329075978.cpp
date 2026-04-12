#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <random>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define INF 999999999

using namespace std;

typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

llong pow(int x, int n) {
    llong ans = x;
    if (n == 0) return 1;

    for(int i = 0; i < n - 1; i++) {
        ans *= x;
    }

    return ans;
}

void swap(int *X, int *Y){
    int t = *X; *X = *Y; *Y = t;
}

const static int MAX = 8 + 1;

int n, m, cnt = 0;
bool visited[MAX];
vector<int> Adj[MAX];

bool check() {
    REP(i, n + 1) {
        if (!visited[i]) return false;
    }

    return true;
}

void dfs(int v) {
    visited[v] = true;
    if (check()) {
        cnt += 1;
        visited[v] = false;
        return;
    }

    for (int i = 0; i < Adj[v].size(); ++i) {
        if (!visited[Adj[v][i]]) dfs(Adj[v][i]);
    }

    visited[v] = false;
}

int main() {
    int a, b;
    cin >> n >> m;
    REP(i, m) {
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    memset(visited, 0, sizeof(n + 1));
    visited[0] = 1;
    dfs(1);

    cout << cnt << endl;

    return 0;
}