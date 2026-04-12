#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;

// 遅延評価セグメント木 lazyRmaxQ
struct lazyRmaxQ{
    ll n;
    vector<ll> node, lazy;

    // 初期化
    lazyRmaxQ(int n_){
        int x = 1;
        while ( x < n_ ) x *= 2;
        n = x;
        node.resize(n*2-1,0);
        lazy.resize(n*2-1,0);
        }
    // 遅延評価
    void eval(int k, int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(r-l > 1){
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    // 値の加算（変更）
    void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
        if(r == -1) r = n;
        eval(k,l,r);
        if (r <= a || b <= l) return;
        else if (a <= l && r <= b){
            lazy[k] = x;
            eval(k,l,r);
        }
        else {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
    // 区間maxを取得する
    ll query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r == -1) r = n;
        if (r <= a || b <= l) return 0;
        eval(k, l, r);
        if (a <= l && r <= b) return node[k];
        else {
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> data(n);
    rep(i,m){
        ll l, r, a; cin >> l >> r >> a; l--; r--; // 区間[l,r]にaを加算 0-indexed
        data[r].pb(make_pair(l,a));
    }

    lazyRmaxQ ans(n);

    rep(i,n){
        ans.update(i, i+1, ans.query(0,i+1));
        for(auto p : data[i]) ans.update(p.first, i+1, p.second);
    }
    cout << max(0ll, ans.query(0,n)) << endl;
    return 0;
}