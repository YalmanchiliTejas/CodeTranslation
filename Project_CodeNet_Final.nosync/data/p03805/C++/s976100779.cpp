#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>

#define PB push_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<30)
#define LLINF (1LL<<60)
#define MOD 1000000007
#define REP(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;

bool graph[8][8];

int dfs(int v, int N, bool visited[8]) {
    bool all_visited = true;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (graph[v][i] == false)continue;
        if (visited[i])continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }

    bool visited[8];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
    return 0;
}
