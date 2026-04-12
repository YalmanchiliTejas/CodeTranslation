#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Node {
    using NP = Node*;

    ll mi, ma, lz;

    void init_node() {
        mi = ma = lz = 0;
    }
    void update() {
        mi = min(l->mi, r->mi);
        ma = max(l->ma, r->ma);
    }
    void push() {
        if (lz) {
            l->lzdata(lz);
            r->lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        mi += x;
        ma += x;
        lz += x;
    }

    void add(int a, int b, ll x) {
        if (b <= 0 or sz <= a) return;
        if (a <= 0 and sz <= b) {
            lzdata(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a - sz/2, b - sz/2, x);
        update();
    }

    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        init_node();
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
        update();
    }
};

int N, N2;
Node* st = nullptr;

int main() {
    scanf("%d", &N); N2 = N/2;
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", a+i);
    }
    st = new Node(N2);
    for (int i = 0; i < N2; i++) {
        st->add(i, i+1, a[i]-a[N-1-i]);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x); l--;
        if (r <= N2) {
//            [l, r)
            st->add(l, r, x);
        } else if (N2 <= l) {
            st->add(N-r, N-l, -x);
        } else {
            st->add(l, N2, x);
            st->add(N-r, N2, -x);
        }
        if (st->mi == 0 and st->ma == 0) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}