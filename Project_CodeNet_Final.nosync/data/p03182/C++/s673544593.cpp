#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

// 区間の情報を二分木で管理
struct LazySegmentTree{
    // 配列サイズを 2 べきにしたときのサイズ
    int sz;
    // 1-indexed で管理
    vector<ll> data;
    vector<ll> lazy;

    LazySegmentTree(int n){
        sz = 1;
        while(sz < n)   sz <<= 1;
        data.assign(sz << 1, 0);
        lazy.assign(sz << 1, 0);
    }

    void set(int idx, const int& x){
        data[idx + sz] = x;
    }

    // k : セグメント木上のインデックス
    //     (set された配列のどの区間かを表す)
    void build(){
        for(int k = sz - 1; k >= 0; --k){
            data[k] = max(data[k << 1], data[k << 1 | 1]);
        }
    }

    // 子ノードへの伝播
    void propagate(int k){
        if(lazy[k] == 0)    return;

        if(k < sz){
            lazy[k << 1] += lazy[k];
            lazy[k << 1 | 1] += lazy[k];
        }
        data[k] += lazy[k];
        lazy[k] = 0;
    }

    // [a, b) の各要素に対して x を一様加算
    ll update(int a, int b, const ll& x, int k = 1, int l = 0, int r = -1){
        if(r == -1) r = sz;
        
        propagate(k);

        // 更新する範囲が今見ている区間内にない
        if(b <= l || r <= a)    return data[k];

        // 更新する区間が今見ている区間を内包している
        else if(a <= l && r <= b){
            lazy[k] += x;
            propagate(k);
            return data[k];     // 子ノードの更新は遅延させる
        }

        else{
            return data[k] = max(update(a, b, x, k << 1, l, (l + r) >> 1),
                                update(a, b, x, k << 1 | 1, (l + r) >> 1, r));
        }
    }

    // [a, b) における最大値を取得
    ll query(int a, int b, int k = 1, int l = 0, int r = -1){
        if(r == -1) r = sz;
        
        propagate(k);
        
        if(b <= l || r <= a)    return 0;
        else if(a <= l && r <= b)   return data[k];
        else{
            return max(query(a, b, k << 1, l, (l + r) >> 1),
                        query(a, b, k << 1 | 1, (l + r) >> 1, r));
        }
    }

    ll operator[](const int& idx){
        return query(idx, idx + 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> table(n + 1);
    for(int i = 0; i < m; ++i){
        int l, r, a;
        cin >> l >> r >> a;
        table[r].emplace_back(l, a);
    }
    LazySegmentTree dp(n + 1);
    for(int i = 1; i <= n; ++i){
        dp.update(i, i + 1, dp.query(0, i));
        for(auto p : table[i]){
            int l = p.first;
            ll a = p.second;
            dp.update(l, i + 1, a);
        }
    }
    cout << dp.query(0, n + 1) << endl;
}