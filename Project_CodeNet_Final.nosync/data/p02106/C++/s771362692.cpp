#include <iostream>
#include <vector>
#include <array>

using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using C = array<int, 10>;
constexpr C e = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

struct Node {
    using NP = Node*;
    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        fill(begin(cnt), end(cnt), 0);
        cnt[0] = 1;
        lz = e;
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
        update();
    }
    C cnt;
    C lz;
    void push() {
        if (lz != e) {
            l->lzdata(lz);
            r->lzdata(lz);
            lz = e;
        }
    }
    void lzdata(C nx) {
        C ncnt = {};
        C nlz = {};
        for (int i = 0; i < 10; i++) {
            nlz[i] = nx[lz[i]];
        }
        for (int i = 0; i < 10; i++) {
            ncnt[nx[i]] += cnt[i];
        }
        lz = nlz;
        cnt = ncnt;
    }
    void update() {
        for (int i = 0; i < 10; i++) {
            cnt[i] = l->cnt[i] + r->cnt[i];
        }
    }
    int get(int a, int b, int c, int d) {
        if (b <= 0 || sz <= a) return 0;
        if (a <= 0 && sz <= b) {
            int u = 0;
            for (int i = c; i <= d; i++) {
                u += cnt[i];
            }
            return u;
        }
        push();
        return l->get(a, b, c, d) + r->get(a - sz/2, b - sz/2, c, d);
    }
    void cng(int a, int b, int c, int d) {
        // c -> d
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            C x = e;
            x[c] = d;
            lzdata(x);
            return;
        }
        push();
        l->cng(a, b, c, d);
        r->cng(a-sz/2, b-sz/2, c, d);
        update();
    }
};

int n, q;
VV<int> g;
V<int> lid, rid;
int nc = 0;
void precalc(int p, int b) {
    lid[p] = nc; nc++;
    for (int d: g[p]) {
        if (d == b) continue;
        precalc(d, p);
    }
    rid[p] = nc;
}

V<int> res;



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    g = VV<int>(n);
    lid = V<int>(n); rid = V<int>(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    precalc(0, -1);

/*    for (int i = 0; i < n; i++) {
        cout << lid[i] << ":" << rid[i] << endl;
    }*/

    Node* tr = new Node(n);
    res = V<int>(q);
    for (int i = 0; i < q; i++) {
        int t, p, x, y;
        cin >> t >> p >> x >> y;
        int l = lid[p], r = rid[p];
        if (t == 1) {
            //count
            cout << tr->get(l, r, x, y) << endl;
        } else {
            //change
            tr->cng(l, r, x, y);
        }
    }
    return 0;
}