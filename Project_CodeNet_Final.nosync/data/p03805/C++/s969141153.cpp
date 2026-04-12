#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n, m;
int ans = 0;
bool visited[10];
vector<vector<int>> graph;

void dfs(int from = 0, int pre = 0){
    int cur = pre | (1 << from);
    if(cur == (1 << n) - 1){
        ++ans;
        return;
    }

    visited[from] = true;
    for(int to : graph[from]){
        if(visited[to]) continue;
        dfs(to, cur);
    }
    visited[from] = false;

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs();
    cout << ans << endl;
}