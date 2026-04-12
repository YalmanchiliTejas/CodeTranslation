#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int n;
vector<vector<int>> to;
vector<bool> seen;
void dfs(int v, int& cnt) {
    seen[v] = true;
    bool flag = true;
    rep(i, n) if (!seen[i]) flag = false;
    if (flag) cnt++;
    for (int i = 0; i < to[v].size(); ++i) {
        int nv = to[v][i];
        if (seen[nv]) continue;
        dfs(nv, cnt);
    }
    seen[v] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin >> n >> m;
    to.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    seen.resize(n, false);
    int cnt = 0;
    dfs(0, cnt);
    cout << cnt << endl;
}