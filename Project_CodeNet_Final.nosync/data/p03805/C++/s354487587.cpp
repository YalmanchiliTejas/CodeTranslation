#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int n, m, a, b;
vector<bool> visited(8, false);
vector<vector<int>> graph(8);

int dfs(int cur) {
    visited[cur] = true;

    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            all_visited = false;
        }
    }
    
    if (all_visited) {
        visited[cur] = false;
        return 1;
    }

    int ans = 0;
    for (int ch : graph[cur]) {
        if (visited[ch]) continue;
        ans += dfs(ch);
    }

    visited[cur] = false;
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    cout << dfs(0) << endl;
    return 0;
}
