#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int n, m;
vec g[10];

void dfs(int& cnt, vector<bool> v, int par) {
    bool check = true;
    rep(i, n) if (!v[i]) check = false;
    if (check) {
        cnt++;
        return;
    }

    for (auto&& c : g[par]) {
        if (!v[c]) {
            v[c] = true;
            dfs(cnt, v, c);
            v[c] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;
    vector<bool> v(n, false);
    v[0] = true;
    dfs(cnt, v, 0);
    cout << cnt << endl;
    return 0;
}