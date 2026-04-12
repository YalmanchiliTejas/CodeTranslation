#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const INF = 1LL<<60;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

struct interval {
    int l,r,v;
    bool operator<(const interval& a) const {
        return r < a.r;
    }
};

struct LazySegmentTree {
private:
    int n;
    vector<ll> node,lazy;
public:
    LazySegmentTree(vector<ll> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1,0);
        for (int i = 0;i < sz;++i) node[i+n-1] = v[i];
        for (int i = n-2;i >= 0;--i) node[i] = min(node[i*2+1],node[i*2+2]);
    }

    void eval(int k,int l,int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k]/(r-l);
            if (r-l > 1) {
                lazy[2*k+1] += lazy[k]/2;
                lazy[2*k+2] += lazy[k]/2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a,int b,ll x,int k = 0,int l = 0,int r = -1) {
        if (r < 0) r = n;
        eval(k,l,r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += (r-l)*x;
            eval(k,l,r);
        } else {
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k] = max(node[2*k+1],node[2*k+2]);
        }
    }

    ll getmax(int a,int b,int k = 0,int l = 0,int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return -INF;
        eval(k,l,r);
        if (a <= l && r <= b) return node[k];
        ll vl = getmax(a,b,k*2+1,l,(l+r)/2);
        ll vr = getmax(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    LazySegmentTree seg(vector<ll>(n+10,0));
    vector<interval> a(m);
    for (int i = 0;i < m;++i) cin >> a[i].l >> a[i].r >> a[i].v;
    sort(a.begin(),a.end());
    int j = 0;
    for (int i = 1;i <= n;++i) {
        seg.add(i,i+1,seg.getmax(0,i+1));
        while (j < m && a[j].r == i) {
            seg.add(a[j].l,a[j].r+1,a[j].v);
            j++;
        }
    }
    cout << seg.getmax(0,n+10) << endl;
    return 0;
}