#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
// #define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (ll i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (ll (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (ll i = (a); (i) < (n); ++(i))
#define dugbe(k) cout << "-\t> " << #k << " : " << k << "\n";
#define dugbev(vec, idx) cout << "-\t> " << #vec << "[" << idx << "] : " << vec[idx] << "\n";
#define debug(args...) { string _debug_list = #args; replace(_debug_list.begin(), _debug_list.end(), ',', ' '); stringstream _debug_stream(_debug_list); istream_iterator<string> __it(_debug_stream); debug_func(__it, args); }

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const long double eps = 1e-7;

const ll N = 1e5 + 5;
const ll INF = 2e9 + 100;
const ll LLINF = 2e18 + 100;

void debug_func(istream_iterator<string> _it)
{
	cerr << "\n";
}

template <typename T, typename... Args>
void debug_func(istream_iterator<string> _it, T x, Args... args)
{
	cerr << "[ " << *_it << " : " << x << " ]";
	cerr << " , ";
	debug_func(++_it, args...);
}

/********* 
	BEGINNING OF SEGMENT TREE SNIPPET.
	Computed in 7 and a half million years by: DeepThought42
 *********
*/

/* Start changes here. */

typedef ll ftype; // Data type that the segment tree is built on. Change 'int' here to whatever is required.
/* You need to define the operations
 *   == and !=
 * for ftype in order to retain compatibility with update ops
 * and lazy propagation.
*/
typedef ll utype; // Data type that an update should use.
/* utype serves a utilitarian purpose as well.
 * In most uses, ftype and utype will be the same.
 * However, having utype be separate from ftype means it's
 * not necessary to have to define update operations when
 * the segment tree doesn't require updates.
 * However, I haven't used utype anywhere yet, because I haven't
 * found the need for it yet.
*/

ftype merge(ftype &lhs, ftype &rhs)
{
	// Defines the merge operation that dictates the segment tree.
	ftype result = min(lhs, rhs);
	return result;
}
const ftype IDENTITY = LLINF; // Identity element of the merge operation.

void perform_update(ftype &tree_node, utype update_value, int seg_size)
{
	// Perform an update on the tree_node.
	// IMPORTANT: 'tree_node' is passed BY REFERENCE.
	tree_node = tree_node + update_value;
}
void update_helper(utype &old_update_value, utype new_update_value)
{
	// Changes the value that will be used to update a tree node.
	// Take caution that 'update_value' is passed by reference
	// for better performance, so don't change it here.
	old_update_value = old_update_value + new_update_value;
}
const utype UPDATE_IDENTITY = 0; // Identity element of the update operation.

/* End changes here (unless internal changes are required). */

// 1-indexed segment tree.
int right(int v)
{
	return (v << 1) ^ 1;
}
int left(int v)
{
	return v << 1;
}

class SegmentTree
{
  public:
	int n;
	vector<ftype> tree;
	bool lazy_propagation = false;
	vector<utype> lazy;
	SegmentTree()
	{
		n = 0;
		tree.clear();
		lazy.clear();
	}
	SegmentTree(int nn)
	{
		n = nn;
		nn = 1;
		while (nn < n)
			nn *= 2;
		tree.assign(2 * nn, IDENTITY);
		lazy.clear();
	}
	SegmentTree(int nn, vector<ftype> &vals)
	{
		*this = SegmentTree(nn);
		int right_bound = (int)vals.size() - 1;
		build(1, vals, 0, right_bound);
		lazy.clear();
	}

	// In all functions that follow, 'v' refers to the current vertex no. in the segment tree.

	// Activates lazy propagation.
	void activate_lazy()
	{
		lazy_propagation = true;
		int segment_tree_size = (int)tree.size();
		lazy.assign(segment_tree_size, UPDATE_IDENTITY);
	}

	// The build function build a segment tree on the range {arr[al], arr[al + 1], ..., arr[ar]} inclusive of both ends.
	void build(int v, ftype *arr, int al, int ar)
	{
		if (al == ar)
		{
			tree[v] = arr[al];
			return;
		}
		int am = (al + ar) >> 1;
		build(left(v), arr, al, am);
		build(right(v), arr, am + 1, ar);
		tree[v] = merge(tree[left(v)], tree[right(v)]);
	}

	void build(int v, vector<ftype> &arr, int al, int ar)
	{
		if (al == ar)
		{
			tree[v] = arr[al];
			return;
		}
		int am = (al + ar) >> 1;
		build(left(v), arr, al, am);
		build(right(v), arr, am + 1, ar);
		tree[v] = merge(tree[left(v)], tree[right(v)]);
	}

	// tl and tr refer to the left and right bounds of the underlying array 'arr' that segment v corresponds to (tree left & tree right).

	// ql and qr refer to the bounds of the query.
	ftype query(int v, int tl, int tr, int ql, int qr)
	{
		if (lazy_propagation)
		{
			if (lazy[v] != UPDATE_IDENTITY)
			{
				perform_update(tree[v], lazy[v], (tr - tl + 1));
				if (tl != tr) // Not a terminal.
				{
					update_helper(lazy[left(v)], lazy[v]);
					update_helper(lazy[right(v)], lazy[v]);
				}
				lazy[v] = UPDATE_IDENTITY;
			}
		}

		if (qr < tl || tr < ql) // If query is entirely out of bounds of the segment.
			return IDENTITY;
		
		if (ql <= tl && tr <= qr) // If the segment is entirely part of the query.
			return tree[v];

		// Break the query into two parts, one on each half segment.
		int tm = (tl + tr) >> 1;
		ftype left_half = query(left(v), tl, tm, ql, qr);
		ftype right_half = query(right(v), tm + 1, tr, ql, qr);
		return merge(left_half, right_half);
	}

	// Update operations.
	// Set arr[idx] = val.
	void update(int v, int tl, int tr, int idx, utype val)
	{
		if (idx < tl || tr < idx)
			return;
		if (tl == tr)
		{
			if (tl == idx)
			{
				perform_update(tree[v], val, (tr - tl + 1));
			}
			return;
		}
		int tm = (tl + tr) >> 1;
		if (idx <= tm)
			update(left(v), tl, tm, idx, val);
		else
			update(right(v), tm + 1, tr, idx, val);
		tree[v] = merge(tree[left(v)], tree[right(v)]);
	}

	// Range update from arr[ul] to arr[ur].
	void update(int v, int tl, int tr, int ul, int ur, utype val)
	{
	/*	if (!lazy_propagation)
		{
			cerr << "Cannot perform range query without lazy propagation activated.\n"
			return;
		}
		*/
		assert(lazy_propagation == true);
		if (lazy[v] != UPDATE_IDENTITY)
		{
			perform_update(tree[v], lazy[v], (tr - tl + 1));
			if (tl != tr) // Not a terminal.
			{
				update_helper(lazy[left(v)], lazy[v]);
				update_helper(lazy[right(v)], lazy[v]);
			}
			lazy[v] = UPDATE_IDENTITY;
		}
		if (ur < tl || tr < ul)
			return;
		if (ul <= tl && tr <= ur)
		{
			perform_update(tree[v], val, (tr - tl + 1));
			if (tl != tr) // Not a terminal.
			{
				update_helper(lazy[left(v)], val);
				update_helper(lazy[right(v)], val);
			}
			return;
		}

		int tm = (tl + tr) >> 1;
		update(left(v), tl, tm, ul, ur, val);
		update(right(v), tm + 1, tr, ul, ur, val);
		tree[v] = merge(tree[left(v)], tree[right(v)]);
	}
};

/*** 

END OF SNIPPET. 

Prototypes:
	void build(int v, ftype *arr, int al, int ar);
	void build(int v, vector<ftype> arr, int al, int ar);
	ftype query(int v, int tl, int tr, int ql, int qr);
	void update(int v, int tl, int tr, int idx, ftype val);
	void update(int v, int tl, int tr, int ul, int ur, ftype val);

***/

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vpr v[n + 1];
	ll sum = 0;
	forl(i, 0, m)
	{
		int l, r, a;
		cin >> l >> r >> a;
		v[r].emplace_back(l, a);
		sum += a;
	}
	SegmentTree S(n + 1);
	vll arr(n + 1, LLINF);
	S.build(1, arr, 0, n);
	S.activate_lazy();

	ll mn = LLINF;
	S.update(1, 0, n, 0, 0, 0 - LLINF);
	for (int i = 1; i <= n + 1; ++i)
	{
		for (auto e: v[i - 1])
		{
			// Add intervals to dp values.
			S.update(1, 0, n, 0, e.ff - 1, e.ss);
		}
		ll res = S.query(1, 0, n, 0, n);
		mn = min(mn, res);

		// Update value of dp[i]
		S.update(1, 0, n, i, res - LLINF);
	}

	sum -= mn;
	cout << sum << "\n";

	return 0;
}