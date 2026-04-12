#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs(int s, int n, vector<vector<int>> &g, vector<bool> flg, int cnt, int &ans) {
    //cout << cnt << endl;
    if (cnt==n) {
        ++ans;
        return;
    }
    flg[s] = true;
    for (auto v: g[s]) {
        if (flg[v]) continue;
        dfs(v, n, g, flg, cnt+1, ans);
    }
    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    vector<bool> flg(n, false);
    dfs(0, n, g, flg, 1, ans);
    cout << ans << endl;
    return 0;
}
