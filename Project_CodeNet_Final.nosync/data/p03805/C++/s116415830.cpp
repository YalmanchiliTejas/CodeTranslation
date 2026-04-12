#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

bool check(int check_num, vector<int> ans) {
    rep(i, ans.size()) {
        if ( ans[i] == check_num ) {
            return false;
        }
    }
    return true;
}

void dfs(int s, vector<vector<int>> &g, vector<int> ans, int n, int &cnt) {
    if ( !check(s, ans) ) {
        return;
    }
    ans.push_back(s);
    if ( ans.size() == n ) {
        ++cnt;
        return;
    }
    for ( auto v : g[s] ) {
        if ( !check(v, ans) ) continue;
        dfs(v, g, ans, n, cnt);
    }
    return;
}

int main(){
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
    int cnt = 0;
    vector<int> ans;
    dfs(0, g, ans, n, cnt);
    cout << cnt << endl;
    return 0;
}
