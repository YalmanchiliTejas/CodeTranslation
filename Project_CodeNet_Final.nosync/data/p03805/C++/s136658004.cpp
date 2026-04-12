#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int Vmax = 8;

int graph[Vmax][Vmax];
bool visited[Vmax];

int dfs(int v, int N) {
    
    int all_visited = 1;
    rep(i, N) {
        if(!visited[i]) {
            all_visited = 0;
        }
    }

    if(all_visited) {
        return 1;
    }

    int cnt = 0;
    rep(i, N) {
        
        if(!graph[v][i] || visited[i]) {
            continue;
        }

        visited[i] = true;

        cnt += dfs(i, N);

        visited[i] = false;
    }

    return cnt;
}

int main() {
    int n;
    int m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;  b--;
        graph[a][b] = graph[b][a] = 1;
    }

    rep(i, n) {
        visited[i] = false;
    }
    visited[0] = true;

    cout << dfs(0, n) << endl;
    return 0;
}