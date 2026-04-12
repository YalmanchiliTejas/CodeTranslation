#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

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
        for (int i = n-2;i >= 0;--i) node[i] = max(node[i*2+1],node[i*2+2]);
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
        if (b <= l || r <= a) return -INT64_MAX;
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
    vector<vector<P>> r(n+1);
    LazySegmentTree dp(vector<ll>(n+1,0));
    for (int i = 0;i < m;++i) {
        int a,b,c;
        cin >> a >> b >> c;
        r[b].push_back(P(a,c));
    }
    for (int i = 1;i <= n;++i) {
        dp.add(i,i+1,dp.getmax(0,i)-dp.getmax(i,i+1));
        for (P p : r[i]) dp.add(p.first,i+1,p.second);
    }
    cout << dp.getmax(0,n+1) << endl;
    return 0;
}