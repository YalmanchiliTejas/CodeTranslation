#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1<<25;

/**
 * ??¨???????????????????????????????????¨?????????Link-Cut Tree
 *
 * ????????¨????????????link???cut???evert???root???????£???????
 * ?????????????????????????????´???????????????????????¨?\¨??????
 * 
 * ??¶?????????????????¨?????????????£?????????°?????????????????§?????¨???????????\???????????????????????????
 * ??????????????????????£??????§????´?2k(????????????)??§???ICPC??§????????¨???????????????
 */
struct LCNode {
    typedef LCNode* NP;

    typedef int D;
    struct Node {
        D mi, lz;
    } n;
    LCNode() : l(nullptr), r(nullptr), sz(0), rev(false) {}
    LCNode(D v) : p(nullptr), l(last), r(last), sz(1), rev(false) {
        n.mi = v;
        n.lz = -1;
    }

    NP update() {
        assert(this != last);
        sz = 1+l->sz+r->sz;
        return this;
    }
    void push() {
        int lsz = l->sz, rsz = r->sz;
        if (n.lz != -1) {
            if (lsz) {
                l->lzdata(n.lz);
            }
            if (rsz) {
                r->lzdata(n.lz);
            }
            n.lz = -1;
        }
        if (rev) {
            if (lsz) {
                l->revdata();
            }
            if (rsz) {
                r->revdata();
            }
            rev = false;
        }
    }

    void lzdata(D lz) {
        n.mi = min(n.mi, lz);
        if (n.lz == -1) n.lz = lz;
        else n.lz = min(n.lz, lz);
    }
    void revdata() {
        assert(this != last);
        swap(l, r);
        rev ^= true;
    }
    D get() {
        expose();
        return n.mi;
    }
    void set(D d) {
        expose();
        lzdata(d);
    }

    //????????????
    static LCNode last_d;
    static NP last;
    NP p, l, r;
    int sz;
    bool rev;
    inline int pos() {
        if (p) {
            if (p->l == this) return -1;
            if (p->r == this) return 1;
        }
        return 0;
    }
    void rot() {
        NP qq = p->p;
        int pps = p->pos();
        if (p->l == this) {
            p->l = r; r->p = p;
            r = p; p->p = this;
        } else {
            p->r = l; l->p = p;
            l = p; p->p = this;
        }
        p->update(); update();
        p = qq;
        if (!pps) return;
        if (pps == -1) {
            qq->l = this;
        } else {
            qq->r = this;
        }
        qq->update();
    }
    void splay() {
        assert(this != last);
        supush();
        int ps;
        while ((ps = pos())) {
            int pps = p->pos();
            if (!pps) {
                rot();
            } else if (ps == pps) {
                p->rot(); rot();
            } else {
                rot(); rot();
            }
        }
    }
    void expose() {
        assert(this != last);
        NP u = this, ur = last;
        do {
            u->splay();
            u->r = ur;
            u->update();
            ur = u;
        } while ((u = u->p));
        splay();
    }
    /**
     * splay?????????????????¬??§???????????????????????¨???????????§???push??????
     * ??????stack overflow???????????¢??°????????§??¨??????????????¨
     */
    void supush() {
        if (pos()) {
            p->supush();
        }
        push();
    }
    //???????????§?????¶?????????

    void link(NP r) {
        assert(this != r);
        expose();
        r->expose();
        assert(l == last);
        p = r;
    }

    void cut() {
        expose();
        l->p = NULL;
        l = last;
        update();
    }

    NP root() {
        expose();
        NP u = this;
        while (u->l != last) {
            u = u->l;
            u->push();
        }
        u->expose(); //????????????????????¨?¨????????????????????????????
        return u;
    }

    NP parent() {
        expose();
        NP u = this->l;
        if (u == last) return nullptr;
        u->push();
        while (u->r != last) {
            u = u->r;
            u->push();
        }
        u->expose();
        return u;
    }
    
    void evert() {
        expose();
        revdata();
    }

    NP lca(NP n) {
        n->expose();
        expose();
        NP t = n;
        while (n->p != nullptr) {
            if (!n->pos()) t = n->p;
            n = n->p;
        }
        return (this == n) ? t : nullptr;
    }
};
LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;


typedef tuple<int, int, int, int> Q;
const int MN = 100100;
const int MM = 200200;

LCNode lct[MN];
LCNode lce[MN];

int W[MM];
int lcec = 0;
int lce2i[MM];
int res[MM];

void main2() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        lct[i] = LCNode(INF);
    }
    vector<Q> v;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        W[i] = w;
        v.push_back(Q(w, a, b, i));
    }
    sort(v.begin(), v.end());
    ll sm = 0;
    int ec = 0;
    for (Q q: v) {
        int a, b, w, idx;
        tie(w, a, b, idx) = q;
        if (lct[a].lca(&lct[b]) == nullptr) {
            sm += w;
            ec++;
            lce[lcec] = LCNode(INF);
            lct[a].evert();
            lct[a].link(&lce[lcec]);
            lce[lcec].link(&lct[b]);
            lce2i[lcec] = idx;
            lcec++;
        } else {
            lct[a].evert();
            lct[b].set(w);
        }
    }

    if (ec != n-1) {
        for (int i = 0; i < m; i++) {
            printf("-1\n");
        }
        return;
    }

    memset(res, -1, sizeof(res));
    for (int i = 0; i < lcec; i++) {
        lce[i].evert();
        res[lce2i[i]] = lce[i].get();
    }

    for (int i = 0; i < m; i++) {
        if (res[i] == -1) {
            printf("%lld\n", sm);
        } else {
            if (res[i] == INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", sm - W[i] + res[i]);
            }
        }
    }
}

ll eord, enew;
int main() {
    const int SZ = 128*1024*1024;
    void *p = malloc(SZ);
    enew = (long long)p + SZ - 1;

//    __asm__("mov %rsp, eord");
//    __asm__("mov enew, %rsp");

    main2();

//    __asm__("mov eord, %rsp");
}