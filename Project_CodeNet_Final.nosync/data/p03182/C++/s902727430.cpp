#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
#define ls i << 1
#define rs i << 1 | 1
class RangeUpdateSegmentTree {
   private:
    struct node {
        int l, r;
        ll adt = 0;
        ll x = 0;
    };
    vector<node> a;
    void push(int i) {
        if (a[i].adt) {
            a[ls].adt += a[i].adt, a[rs].adt += a[i].adt;
            //a[ls].x += a[i].adt, a[rs].x += a[i].adt;
            a[i].adt = 0;
        }
    }
    void pull(int i) {
        a[i].x = max(a[ls].x + a[ls].adt, a[rs].x + a[rs].adt);
    }
    void build(int l, int r, int i) {
        a[i].l = l, a[i].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, ls), build(mid + 1, r, rs);
    }
   public:
    RangeUpdateSegmentTree(int n) : a(n << 2) {
        build(0, n, 1);
    }
    void add(int l, int r, ll val, int i = 1) {
        if (a[i].l >= l && a[i].r <= r) {
            a[i].adt += val;
            return;
        }
        push(i);
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) add(l, r, val, ls);
        if (r > mid) add(l, r, val, rs);
        pull(i);
    }
    ll maxx(int l, int r, int i = 1) {
        if (l <= a[i].l && a[i].r <= r) return a[i].x + a[i].adt;
        push(i);
        ll ret = -9e18;
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) ret = max(ret, maxx(l, r, ls));
        if (r > mid) ret = max(ret, maxx(l, r, rs));
        pull(i);
        return ret;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> add(n + 1);
	vector<vector<pil>> del(n + 1);
	for (int i = 0; i < m; i++) {
		int l, r; ll a;
		cin >> l >> r >> a;
		add[l] += a;
		del[r].push_back(pil(l, a));
	}
	RangeUpdateSegmentTree ST(n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ST.add(0, i - 1, add[i]);
		ll tmp = ST.maxx(0, i - 1);
		ans = max(ans, tmp);
		ST.add(i, i, tmp);
		for (pil p : del[i])
			ST.add(0, p.first - 1, -p.second);
	}
	cout << ans << "\n";
	return 0;
}