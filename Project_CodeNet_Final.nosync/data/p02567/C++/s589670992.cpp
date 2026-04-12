#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

#include <atcoder/segtree>

using namespace std;
using namespace atcoder;
#define rep(i,l,r) for(int i = l; i < r; ++i)

int e() {return 0;}
int op(int s1, int s2) {return max(s1, s2);}
int v;
int f(int s) {return s < v;}

int main() {
    int n, q, t, x, y;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    segtree<int, op, e> st(a);
    rep(i, 0, q) {
        cin >> t >> x >> y;

        if (t == 1) {
            st.set(x - 1, y);
        } else if (t == 2) {
            cout << st.prod(x - 1, y) << endl;
        } else {
            v = y;
            cout << st.max_right(x - 1, f) + 1 << endl;
        }
    }
}
