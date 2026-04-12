#include <bits/stdc++.h>

#define x first
#define y second
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }
template <typename T> T read ()
{
	T sum = 0, fl = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
	return sum * fl;
}

inline void proc_status()
{
	ifstream t ("/proc/self/status");
	cerr << string (istreambuf_iterator <char> (t), istreambuf_iterator <char> ()) <<endl;
}

const int Maxn = 2e5 + 100;

int N, M;
struct info
{
	int l, r, w;
} A[Maxn];

inline int cmp (info a, info b) { return a.r < b.r; }

namespace SEG
{
#define mid ((l + r) >> 1)
#define ls node[root << 1]
#define rs node[root << 1 | 1]
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
	struct tree
	{
		LL max, tag;
	}node[Maxn << 2];

	inline void push_up (int root) { node[root].max = max(ls.max, rs.max); }

	inline void push_down (int root, int l, int r)
	{
		if (!node[root].tag) return ;
		ls.tag += node[root].tag; ls.max += node[root].tag;
		rs.tag += node[root].tag; rs.max += node[root].tag;
		node[root].tag = 0;
	}

	inline void update (int root, int l, int r, int x, int y, LL z)
	{
		if (x <= l && r <= y) node[root].max += z, node[root].tag += z;
		else
		{
			push_down(root, l, r);
			if (x <= mid) update (lson, x, y, z);
			if (y > mid) update (rson, x, y, z);
			push_up (root);
		}
	}

	inline LL query (int root, int l, int r, int x, int y)
	{
		if (x <= l && r <= y) return node[root].max;
		else
		{
			push_down(root, l, r);
			LL ans = 0;
			if (x <= mid) ans = max(ans, query (lson, x, y));
			if (y > mid) ans = max(ans, query (rson, x, y));
			return ans;
		}
	}

#undef mid
#undef ls
#undef rs
#undef lson
#undef rson
}

inline void Solve ()
{
	sort(A + 1, A + M + 1, cmp);
	
	int j = 1;
	for (int i = 1; i <= N; ++i)
	{
		SEG :: update (1, 1, N, i, i, SEG :: query (1, 1, N, 1, i));

		while (A[j].r == i)
		{
			SEG :: update (1, 1, N, A[j].l, A[j].r, A[j].w);
			++j;
		}
	}

	cout<<max(0ll, SEG :: node[1].max)<<endl;
}

inline void Input ()
{
	N = read<int>(), M = read<int>();
	for (int i = 1; i <= M; ++i)
		A[i].l = read<int>(), A[i].r = read<int>(), A[i].w = read<int>();
}

int main()
{
#ifdef hk_cnyali
	freopen("W.in", "r", stdin);
	freopen("W.out", "w", stdout);
#endif
	Input();
	Solve();
	return 0;
}
