#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
// for (int bit = (1<<k)-1 ;bit < (1<<n); bit = next_combination(bit))

int n, m, ans;
vector<vector<int>> to;
vector<bool> seen;

void dfs(int v) {
    seen[v] = true;
    bool flag = true;
    rep(i, n) {
        if (!seen[i]) {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    for (auto nv : to[v]) {
        if (seen[nv]) continue;
        dfs(nv);
    }
    seen[v] = false;
}

int main(){
    cin >> n >> m;
    to.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].emplace_back(b);
        to[b].emplace_back(a);
    }

    seen = vector<bool>(n, false);
    dfs(0);
    cout << ans << endl;
}
