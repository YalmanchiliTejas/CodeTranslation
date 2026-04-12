//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int n, m, ans = 0;
vector<vector<int>> to(10, vector<int>());
vector<bool> saw(10, false);

void dfs(int v) {
    bool flag = true;
    rep(i, n) {
        if (!saw[i]) flag = false;
    }
    if (flag) {
        ans++;
        return;
    }
    for (int nv : to[v]) {
        if (saw[nv]) continue;
        saw[nv] = true;
        dfs(nv);
        saw[nv] = false;
    }
}


int main () {
    cin >> n >> m;
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> vec(n);
    rep(i, n) vec[i] = i;
    saw[0] = true;
    dfs(0);
    cout << ans << endl;
    return 0;
}