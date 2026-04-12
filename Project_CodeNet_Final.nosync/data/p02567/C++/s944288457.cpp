#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

struct SegmentTree {
private:
    int n;
    vector<int> node;
public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1,0);
        for (int i = 0;i < sz;++i) node[i+n-1] = v[i];
        for (int i = n-2;i >= 0;--i) node[i] = max(node[2*i+1],node[2*i+2]);
    }
    void update(int x,int val) {
        x += (n-1);
        node[x] = val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = max(node[2*x+1],node[2*x+2]);
        }
    }

    int getmax(int a,int b,int k = 0,int l = 0,int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = getmax(a,b,2*k+1,l,(l+r)/2);
        int vr = getmax(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }

    int find(int a,int b,int x,int k = 0,int l = 0,int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l || node[k] <= x) return b;
        if (k >= n-1) return k-n+1;
        int vl = find(a,b,x,2*k+1,l,(l+r)/2);
        if (vl != b) return vl;
        return find(a,b,x,2*k+2,(l+r)/2,r);
    }
};

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    SegmentTree seg(a);
    for (int i = 0;i < q;++i) {
        int t,x,v;
        cin >> t >> x >> v;
        if (t == 1) seg.update(x-1,v);
        else if (t == 2) cout << seg.getmax(x-1,v) << newl;
        else cout << seg.find(x-1,n,v-1)+1 << newl;
    }
}