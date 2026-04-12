#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 4e18;

struct Node {
    typedef Node* NP;
    NP l, r;
    int sz;
    ll ma, lz;
    Node(int _sz) : sz(_sz), ma(-INF), lz(0) {
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
    void apply(ll d) {
        ma += d;
        lz += d;
    }
    void push() {
        l->apply(lz);
        r->apply(lz);
        lz = 0;
    }
    void pull() {
        ma = max(l->ma, r->ma);
    }
    void set(int k, ll x) {
        if (sz == 1) {
            ma = max(ma, x);
            return;
        }
        push();
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        pull();
    }
    void add(int a, int b, ll x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            apply(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a-sz/2, b-sz/2, x);
        pull();
    }
    ll get(int a, int b) {
        if (b <= 0 || sz <= a) return -INF;
        if (a <= 0 && sz <= b) return ma;
        push();
        return max(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }
};

using P = pair<int, int>;
const int MN = 233333;
int n, m;
vector<P> g[MN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[y].push_back(P(x, z));
    }

    Node* tr = new Node(n+1);
    tr->set(0, 0);
    for (int i = 1; i <= n; i++) {
        tr->set(i, tr->get(0, i));
        for (auto &p : g[i]) {
            tr->add(p.first, i+1, p.second);
        }
    }
    cout << tr->get(0, n+1) << "\n";
    return 0;
}