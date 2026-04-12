#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

struct segment_tree
{
	int n;
	vector<int> a;

	segment_tree(int n) : n(n), a(2 * n) {}

	void update(int p, int v)
	{
		for (a[p += n] = v; p /= 2;)
			a[p] = min(a[2 * p], a[2 * p + 1]);
	}

	int query(int l, int r)
	{
		int g = 1<<30;

		for (l += n, r += n; l < r; l /= 2, r /= 2)
		{
			if (l & 1) g = min(g, a[l++]);
			if (r & 1) g = min(g, a[--r]);
		}

		return g;
	}
};

vector<int> lis(const vector<int> &a)
{
	vector<int> l, who(a.size()), where(a.size());
	for (auto &i : a)
	{
		auto it = upper_bound(l.begin(), l.end(), i) - l.begin();
		where[&i-&a[0]] = !it ? -1 : who[it-1];
		if (it == l.size()) l.emplace_back();
		l[it] = i, who[it] = &i-&a[0];
	}

	vector<int> ans;
	for (int p = who[l.size()-1]; p != -1; p = where[p])
		ans.push_back(p);

	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	#ifdef TurnRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	for (auto &i : a) i *= -1;
	cout << lis(a).size() << "\n";

//	segment_tree st(n);
//	for (int i = 0; i < n; ++i)
//		st.update(i, a[i]);
//
//	int ans = n;
//	for (int i = n-1; i >= 1; --i)
//	{
//		int l = 0, r = i-1;
//		while (l < r)
//		{
//			int m = (l + r + 1) >> 1;
//			if (st.query(m, i) < a[i])
//				l = m;
//			else
//				r = m-1;
//		}
//		if (st.query(l, l+1) < a[i])
//		{
//			--ans;
//			st.update(l, 1<<30);
//		}
//	}
//	cout << ans << "\n";

	return 0;
}
