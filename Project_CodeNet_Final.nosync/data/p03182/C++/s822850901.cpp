#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


template<typename T> class LazyRMQ {
    public:
    int n;
    T inf = INF;
    vector<T> data, lazy;
    
    LazyRMQ(int m, T init_value=-INF){
        // 2のべき乗にする
        n = 1;
        while(n < m) n <<= 1;
        data.assign(2*n-1, init_value);
        lazy.assign(2*n-1, 0);
        inf = init_value;
    }

    void eval(int k, int kl, int kr){
        if(data[k] == inf) data[k] = 0;
        if(lazy[k] == 0) return;
        data[k] += lazy[k];
        if(kr - kl > 1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    // [s,t)
    void add(int s, int t, T x, int k, int kl, int kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return;
        if(s <= kl && kr <= t){
            lazy[k] += x;
            eval(k, kl, kr);
            return;
        }
        int kc = (kl+kr)/2;
        add(s, t, x, 2*k+1, kl, kc);
        add(s, t, x, 2*k+2, kc, kr);
        data[k] = max(data[2*k+1], data[2*k+2]);
    }

    void add(int s, int t, T x) {
        add(s, t, x, 0, 0, n);
    }

    // [s,t)
    T find(int s, int t, int k, int kl, int kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return inf;
        if(s <= kl && kr <= t) return data[k];
        int kc = (kl+kr)/2;
        T vl = find(s, t, 2*k+1, kl, kc);
        T vr = find(s, t, 2*k+2, kc, kr);
        return max(vl, vr);
    }

    T find(int s, int t) {
        return find(s, t, 0, 0, n);
    }
};

int main() {
    int n,m,l,r; ll a;
    cin >> n >> m;
    vector<pair<int, ll>> ranges[n+1];
    for(int i=0;i<m;++i) {
        cin >> l >> r >> a;
        ranges[r].emplace_back(l, a);
    }

    LazyRMQ<ll> tree(n+2, -(1<<30));
    for(int i=1;i<=n;++i) {
        ll opt = tree.find(0, i);
        tree.add(i, i+1, opt);
        for(pair<int, ll> p: ranges[i]) {
            tree.add(p.first, i+1, p.second);
        }
    }

    cout << tree.find(0, n+1) << endl;
}