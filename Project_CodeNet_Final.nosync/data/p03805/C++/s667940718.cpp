#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;

struct UnionFind {
    vector<ll> par;
    vector<ll> rank;

    UnionFind(ll N) : par(N),rank(N){
        // 初期化
        rep(i,N) {
            par[i] = i;
            rank[i] = 0;
        }
    }


    ll root(ll x){
        // unionfind木をたどって頂点を探す
        if(par[x]==x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(ll x,ll y){
        // 高さを考慮し、結合する。
        ll rx = root(x);
        ll ry = root(y);
        if(rx==ry) return;
        if(rank[x]<rank[y]){
            par[rx] = y;
        }else{
            par[ry] = x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }

    bool same(ll x,ll y){
        // 親が同じなら同じグループ
        return root(x)==root(y);
    }

};

ll ans = 0;
ll n;
vector<vector<ll>> a;
vector<ll> b;

void dfs(ll start){
    // b[start] = 1;
    bool r = true;
    rep(i,n){
        if(b[i]==0) r = false;
    }
    if(r) {
        ans++;
        // cout << start << endl;
        return;
    }

    for(ll v:a[start]){
        if(b[v]==0){
            b[v] = 1;
            dfs(v);
            b[v] = 0;
        }
    }
    return;
}


void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll m;
    cin >> m;
    a.resize(n,vector<ll>());
    b.resize(n);
    rep(i,m){
        ll q,w;
        cin >> q >> w;q--;w--;
        a[q].push_back(w);
        a[w].push_back(q);
    }
    b[0] = 1;

    dfs(0);

    cout << ans;




    return 0;
}