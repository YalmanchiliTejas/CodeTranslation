#include <bits/stdc++.h>

#define MAXN 200005
#define int long long
#define LL long long
#define pii pair<long, long>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int N, M;

struct Seg {
    int idx, l, r, m, tag, val;
    void build(int id, int s, int e);
    Seg& left();
    Seg& right();
    void pushdown();
    void update(int s, int e, int off);
    int query(int s, int e);
} nodes[MAXN*4];
Seg& Seg::left() { return nodes[idx*2]; };
Seg& Seg::right() { return nodes[idx*2+1]; }
void Seg::build(int id, int s, int e) {
    idx = id, l = s, r = e, m = (l+r)>>1, tag = 0, val = 0;
    if (l != r) left().build(id*2, s, m), right().build(id*2+1, m+1, e);
}
void Seg::pushdown() {
    if (l == r) return;
    if (tag) {
        left().update(l, m, tag);
        right().update(m+1, r, tag);
        tag = 0;
    }
}
void Seg::update(int s, int e, int off) {
    if (l == s && r == e) {
        tag += off, val += off;
        return;
    }
    pushdown();
    if (e <= m) left().update(s, e, off);
    else if (s > m) right().update(s, e, off);
    else left().update(s, m, off), right().update(m+1, e, off);
    val = max(left().val, right().val);
}
int Seg::query(int s, int e) {
    if (l == s && e == r) return val;
    pushdown();
    if (e <= m) return left().query(s, e);
    if (s > m) return right().query(s, e);
    return max(left().query(s, m), right().query(m+1, e));
}

pair<pii, int> a[MAXN];

signed main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    }
    nodes[1].build(1, 0, N);
    sort(a+1, a+1+M, [](const pair<pii, int>& p1, const pair<pii, int>& p2) {
        return p1.fi.se < p2.fi.se;
    });
    int j = 1;
    for (int i = 1; i <= N; i++) {
        nodes[1].update(i, i, nodes[1].query(0, i) - nodes[1].query(i, i));
        while (j <= M && a[j].fi.se <= i) {
            nodes[1].update(a[j].fi.fi, a[j].fi.se, a[j].se);
            j++;
        }
    }
    cout << nodes[1].query(0, N) << endl;
    return 0;
}