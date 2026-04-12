#include"bits/stdc++.h"
#include<atcoder/segtree.hpp>
using namespace atcoder;
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pll = pair<ll, ll>;
using tp3 = tuple<ll, ll, ll>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
// ============ template finished ============

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N)cin >> A[i];

    segtree<int, op, e> seg(A);
    rep(_, Q) {
        int T;
        cin >> T;
        if (T == 1) {
            int X, V;
            cin >> X >> V;
            X--;
            seg.set(X, V);
        }
        else if (T == 2) {
            int L, R;
            cin >> L >> R;
            L--;
            cout << seg.prod(L, R) << endl;
        }
        else {
            int X, V;
            cin >> X >> V;
            X--;
            auto f = [&](int val) {
                return val < V;
            };
            cout << seg.max_right(X, f) + 1 << endl;
        }
    }
    return 0;
}
