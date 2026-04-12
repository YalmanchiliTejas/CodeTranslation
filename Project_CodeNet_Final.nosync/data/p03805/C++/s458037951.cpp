#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ab;
vector<bool> chk_flg;
int ans = 0;
int n, m;

void dfs ( int x = 0 ) {
    chk_flg[x] = true;
    for ( auto n: ab[x] ) {
        if ( chk_flg[n] ) continue;
        dfs(n);
    }
    bool chk_all = true;
    for ( int i = 0; i < n; i++ ) {
        if ( !chk_flg[i] ) chk_all = false;
    }

    if ( chk_all ) {
        ans++;
    }
    chk_flg[x] = false;
}

int main() {

    cin >> n >> m;

    ab.resize(n);
    chk_flg.resize(n);
    for ( int i = 0; i < n; i++ ) {
        ab[i].resize(1);
        chk_flg[i] = false;
    }

    for ( int i = 0; i < m; i++ ) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }

    dfs();

    cout << ans << endl;

    return 0;
}