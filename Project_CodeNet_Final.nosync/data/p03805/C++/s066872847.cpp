#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> g, dp;

int rec(int v, int s){
    if(dp[v][s] > 0) return dp[v][s];
    if(s == (1<<n)-1) return dp[v][s] = 1;

    int ret = 0;
    for(int nv: g[v]){
        if(s & (1<<nv)) continue;
        ret += rec(nv, (s|(1<<nv)));
    }

    return dp[v][s] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    g.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dp.resize(n, vector<int>(1<<n, 0));
    cout << rec(0, 1) << endl;

    return 0;
}