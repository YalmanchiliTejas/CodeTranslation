#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, i, j, k,m;
    cin >> n >> m;
    vector<set<ll>> G(n);
    for(i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        G[--x].insert(--y);
        G[y].insert(x);
    }
    ll ret = 0;
    vector<ll> v(n-1);
    iota(v.begin(),v.end(),1);
    do{
        ll now = 0,ok=1;
        for(i=0;i<n-1;i++){
            if(G[now].find(v[i])==G[now].end()){
                ok = 0;
                break;
            }
            now = v[i];
        }
        if(ok)ret++;

    }while(next_permutation(v.begin(),v.end()));
    cout << ret << endl;
    return 0;
}