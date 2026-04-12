#include<atcoder/all>
using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int RMQ_op(int a, int b) { return max(a, b); }
int RMQ_e() { return -1; }
struct RMQ_cmp { int tg; bool operator()(int v) const { return v < tg; } };

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<int> A(N); rep(i, N) { int a; scanf("%d", &a); A[i] = a; }
    segtree<int, RMQ_op, RMQ_e> G(A);

    rep(q, Q) {
        int c; scanf("%d", &c);
        if (c == 1) {
            int x, v; scanf("%d%d", &x, &v); x--;
            G.set(x, v);
        }
        if (c == 2) {
            int l, r; scanf("%d%d", &l, &r); l--;
            printf("%d\n", G.prod(l, r));
        }
        if (c == 3) {
            int x, v; scanf("%d%d", &x, &v); x--;
            printf("%d\n", G.max_right(x, RMQ_cmp{ v }) + 1);
        }
    }

    return 0;
}