#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

vector<vector<int>> to;
int cnt = 0;
vb seen;
int n, m;

void dfs(int v) {
    if (seen[v]) return;
    seen[v] = true;
    bool ok = true;
    rep(i, n) {
        if (!seen[i]) {
            ok = false;
            break;
        }
    }
    if (ok) cnt++;
    for (auto u : to[v]) dfs(u);
    seen[v] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    to.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].pb(b);
        to[b].pb(a);
    }
    seen.resize(n, false);
    dfs(0);
    cout << cnt << endl;
}