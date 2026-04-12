#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e16)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct query {
    public:
        int time;
        int l;
        int r;
        ll val;

        query(int time_, int l_, int r_, ll val_) {
            time = time_;
            l = l_;
            r = r_;
            val = val_;
        }
    bool operator<(const query& in) const {
        return time < in.time;
    }
};

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 200050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
        if(lazy[k] != 0) {
            node[k] += lazy[k];

        // 最下段かどうかのチェックをしよう
        // 子ノードは親ノードの 1/2 の範囲であるため、
        // 伝播させるときは半分にする
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }

        // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

    // 範囲外なら何もしない
        if(b <= l || r <= a) return;
    
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // 関数が呼び出されたらまず評価！
        eval(k, l, r);

        if(b <= l || r <= a) return -INF;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

    void update(int a, ll x) {
        ll val = getmax(a, a + 1);
        add(a, a + 1, -val + x);
        return;
    }

};



int main() {
    //cout.precision(10);
    LazySegmentTree seg;
    int n, m;
    cin >> n >> m;
    vector<query> queries;
    query Last(1e9, 1e9, 1e9, 0);
    queries.push_back(Last);
    for(int i = 1; i <= m; i++){
        ll l, r, a;
        cin >> l >> r >> a;
        query Q(l, 0, l, a);
        queries.push_back(Q);
        Q.time = r + 1;
        Q.val = -a;
        queries.push_back(Q);
        //queries.
    }
    sort(queries.begin(), queries.end());
    for(int i = 0; i < 2 * m; i++){
        //cout << queries[i].val << endl;
    }
    int Q_index = 0;
    for(int index = 1; index <= n + 1; index++){
        while(queries[Q_index].time == index){
            query now = queries[Q_index];
            Q_index++;
            seg.add(now.l, now.r, now.val);
        }
        ll New_val = seg.getmax(0, index);
        //cout << index << " " << New_val << endl;
        seg.add(index, index + 1, New_val);
    }
    cout << seg.getmax(0, n + 1) << endl;
    return 0;
}
