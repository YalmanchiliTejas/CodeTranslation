#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 200000;

template<typename T> class LazyRMQ {
    public:
    int n;
    T inf = INT_MAX;
    vector<T> data, lazy;
    
    LazyRMQ(int m, T init_value=INT_MAX){
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
        ll opt = tree.find(0, i, 0, 0, tree.n);
        tree.add(i, i+1, opt, 0, 0, tree.n);
        for(pair<int, ll> p: ranges[i]) {
            tree.add(p.first, i+1, p.second, 0, 0, tree.n);
        }
    }

    cout << tree.find(0, n+1, 0, 0, tree.n) << endl;
}