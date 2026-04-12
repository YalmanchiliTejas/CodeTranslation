#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define NMAX 10

ll n, m;
ll rec[NMAX][1<<NMAX];
vector<vector<ll>> G;

void init() {
    rep(i, 0, NMAX) {
        rep(j, 0, 1<<NMAX) rec[i][j] = -1;
    }
}

ll dfs(ll cur, ll bit) {
    if(rec[cur][bit] != -1) return rec[cur][bit];
    if(bit == (1<<n)-1) return rec[cur][bit] = 1;
    ll res = 0;
    for(auto g : G[cur]) {
        if(!(bit & (1<<g))) res += dfs(g, bit | (1<<g));
    }
    return rec[cur][bit] = res;
}

int main(){
    init();
    cin >> n >> m;
    G.resize(n);
    rep(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << dfs(0, 1) << endl;
    return 0;
}