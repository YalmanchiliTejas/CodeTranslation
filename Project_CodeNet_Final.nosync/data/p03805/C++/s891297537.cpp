#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

vector<vector<bool>> v;
vector<bool> visited;
int n;

int dfs(int idx, int c) {
    int ans = 0;
    // printf("idx:%d, c:%d\n", idx, c);

    if (c == n) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (v[idx][i] == true && visited[i] == false) {
            visited[i] = true;
            ans += dfs(i, c + 1);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    v.resize(n, vector<bool>(n, false));
    visited.resize(n, false);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        v[a][b] = v[b][a] = true;
    }

    visited[0] = true;
    int ans = dfs(0, 1);

    cout << ans << endl;

    return 0;
}
