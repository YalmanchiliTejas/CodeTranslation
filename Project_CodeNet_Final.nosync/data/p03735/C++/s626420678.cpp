#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1000000000000000;

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

int main()
{
    int n;
    cin >> n;
    P p[200003];
    ll l = 0, s = INF;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        p[i] = P(max(x, y), min(x, y));
        l = max(l, p[i].second);
        s = min(s, p[i].second);
    }
    sort(p, p + n);
    ll ans = (p[n - 1].first - p[0].first) * (l - s);
    SegmentTree<ll> seg(n, [](ll a, ll b){return min(a, b);}, INF);
    for(int i = 0; i < n; i++) seg.set(i, p[i].second);
    seg.build();
    for(int i = 0; i < n; i++){
        seg.update(i, p[i].first);
        l = max(l, p[i].first);
        ans = min(ans, (p[n - 1].first - s) * (l - seg.query(0, n)));
    }
    cout << ans << endl;
}