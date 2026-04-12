// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int N, M;
vector<int> graph[10];

char visited[10];
int dfs(int v, int depth) {
    if (depth >= N) return 1;
    int ret = 0;
    for (int w : graph[v]) {
        if (visited[w]) continue;
        visited[w] = true;
        ret += dfs(w, depth+1);
        visited[w] = false;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[0] = true;
    cout << dfs(0, 1) << endl;
    return 0;
}
