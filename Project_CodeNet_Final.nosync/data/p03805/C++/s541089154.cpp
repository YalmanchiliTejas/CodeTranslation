/*
    Created by 10_months
    Tag:
    Link:
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
                
using namespace std;

const long long inf = 1e17;
const int INF = 1e9;
const int N = 1234567;
const int M = 123456;

vector <int> e[N];
int n, m, ans, visit[N];

inline void dfs(int u, int k) {
    int sz = e[u].size();
    if (k == n) {
        ans++;
    }
    for (int i = 0; i < sz; i++) {
        int to = e[u][i];
        if (!visit[to]) {
            visit[to] = 1;
            dfs(to, k + 1);
            visit[to] = 0;
        }
    }
}
                         
int main() {
    #ifdef home
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    visit[1] = 1; dfs(1, 1);
    cout << ans << endl;
    return 0;
}