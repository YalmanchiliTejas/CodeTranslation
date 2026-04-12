#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int f_target;
bool f(int val) { return val < f_target; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for_(i,0,N) cin >> a[i];

    segtree<int, op, e> seg(a);
    for_(i,0,Q) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            seg.set(x - 1, v);
        }

        if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l - 1, r) << endl;
        }

        if (t == 3) {
            int x, v;
            cin >> x >> v;
            f_target = v;
            cout << seg.max_right<f>(x - 1) + 1 << endl;
        }
    }
}