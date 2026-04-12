#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll N, M;
vector<vector<ll>> G;

ll dfs(ll i, vector<ll> seen){
    ll ret = 0;
    bool f = false;
    seen[i] = true;
    for(auto p : G[i]){
        if(seen[p]) continue;
        f = true;
        ret += dfs(p, seen);
    }
    if(!f){
        bool ff = false;
        rep(i, 1, N+1){
            if(!seen[i]) ff = true;
        }
        if(ff) return 0;
        else return 1;
    }
    return ret;
}

int main(){
    cin >> N >> M;
    G.resize(N+1);
    rep(i, 0, M){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> seen1(N+1, false);
    cout << dfs(1, seen1) << endl;
    return 0;
}