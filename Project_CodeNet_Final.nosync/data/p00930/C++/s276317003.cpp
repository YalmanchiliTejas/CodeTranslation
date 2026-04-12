#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

class segtree {
public:
    struct node {
        int mi, sum, mii;
        node() {}
        node(int mi, int sum, int mii) : mi(mi), sum(sum), mii(mii) {}
    };
private:
    int n, s, t;
    vector<node> tr;

    node f(node a, node b) {
        return node(min(a.mi, a.sum + b.mi), a.sum + b.sum, a.mi < a.sum + b.mi ? a.mii : b.mii);
    }
    const node ex = node(M, 0, -1);
    node q(int k, int l, int r) {
        return r <= s || t <= l ? ex : s <= l && r <= t ? tr[k]
                : f(q(k << 1 | 1, l, (l + r) >> 1), q((k + 1) << 1, (l + r) >> 1, r));
    }

public:
    segtree(int m) {
        n = 1;
        while (n < m) n <<= 1;
        tr.clear();
        tr.resize((n << 1) - 1, ex);
    }
    void update(int j, const int& x) {
        int i = j + n - 1;
        tr[i] = node(x, x, j);
        while (i > 0) { i = (i - 1) >> 1; tr[i] = f(tr[i << 1 | 1], tr[(i + 1) << 1]); }
    }
    // [s, t)
    node run(int _s, int _t) { s = _s; t = _t; return q(0, 0, n); }
};



int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    set<int> cp;
    segtree sg(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            sg.update(i, 1);
        else {
            sg.update(i, -1);
            cp.insert(i);
        }
    }
    for (int _ = 0; _ < q; ++_) {
        int t;
        cin >> t;
        --t;
        if (s[t] == '(') {
            cp.insert(t);
            sg.update(t, -1);

            s[t] = ')';

            int u = *cp.begin();
            cp.erase(cp.begin());
            sg.update(u, 1);

            s[u] = '(';
            cout << u + 1 << "\n";
        }
        else {
            cp.erase(t);
            sg.update(t, 1);

            s[t] = '(';

            segtree::node nod = sg.run(0, n);
            if (nod.mi == 0)
                nod = sg.run(nod.mii + 1, n);

            int u = nod.mii + 1;
            cp.insert(u);
            sg.update(u, -1);

            s[u] = ')';
            cout << u + 1 << "\n";
        }
    }
    return 0;
}

