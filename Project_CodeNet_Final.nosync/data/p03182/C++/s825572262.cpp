#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

const int MAX = 2e5 + 9;
const LL INFL = 1e17;

struct SegmentTree
{
    LL a[MAX << 2], lz[MAX << 2];
    #define MID ((lo + hi) >> 1)
    #define ROOT0 (root<<1)
    #define ROOT1 (root<<1|1)

    SegmentTree() {}

	void upd (int root, int lo, int hi, int l, int r, LL x)
	{
        if (l > hi || lo > r) return;
        if (l <= lo && hi <= r) { a[root] += x, lz[root] += x; return; }
        lz[ROOT0] += a[root], lz[ROOT1] += a[root], a[ROOT0] += a[root], a[ROOT1] += a[root], a[root] = 0;
        upd (ROOT0, lo, MID, l, r, x);
        upd (ROOT1, MID + 1, hi, l, r, x);
		lz[root] = max(lz[ROOT0], lz[ROOT1]);
	}
	void upd (int l, int r, LL x) { upd (1, 0, MAX - 1, l, r, x); }

    LL get (int root, int lo, int hi, int l, int r)
    {
        if (l > hi || lo > r) return 0;
        if (l <= lo && hi <= r) return lz[root];
        return a[root] + max (get(ROOT0, lo, MID, l, r), get(ROOT1, MID + 1, hi, l, r));
    }
    LL get (int l, int r) { return get (1, 0, MAX - 1, l, r); }
} st;

struct Score
{
    int l, r; LL x;
    Score () {}
    Score (int l, int r, LL x): l(l), r(r), x(x) {}
    bool operator< (const Score &s) const
    {
        return r < s.r;
    }
} scores[MAX];

int N, M;

signed main()
{
//	st.upd (2, 4, 4);
//	st.upd (3, 4, 9);
//	cerr << st.get(2, 2) << endl;
//	return 0;

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) cin >> scores[i].l >> scores[i].r >> scores[i].x;
    sort (scores, scores + M);
    int last = 0;
    for (int i = 0; i < M; ++i) {
        Score sc = scores[i];
        if (last + 1 <= sc.r) st.upd (last + 1, sc.r, st.get(0, last));
//        cerr << "S" << last + 1 << ' ' << sc.r << ' ' << st.get(0, last) << endl;
//        for (int j = 1; j <= 6; ++j) cerr << st.get(j, j) << ' '; cerr << endl << endl;
        st.upd (sc.l, sc.r, sc.x);
//        cerr << "S" << sc.l << ' ' << sc.r << ' ' << sc.x << endl;
//        for (int j = 1; j <= 6; ++j) cerr << st.get(j, j) << ' '; cerr << endl << endl;
        last = sc.r;

//        cerr << sc.l << ' ' << sc.r << ' ' << sc.x << endl;
//        for (int j = 1; j <= 6; ++j) cerr << st.get(j, j) << ' '; cerr << endl << endl;
    }
    cout << st.get(0, MAX - 1) << endl;
}
