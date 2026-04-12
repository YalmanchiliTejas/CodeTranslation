
// Problem : C - Many Medians
// Contest : AtCoder Regular Contest 095
// URL : https://atcoder.jp/contests/arc095/tasks/arc095_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;

// begin of indexed_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
// end of indexed_set

using ll = long long;
#define size(x) (int)x.size()

const int N = 2e5 + 1, MAX = 1e9;

int n, a[N];
indexed_multiset im;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		im.insert({a[i], i});
	}
	for (int i = 1; i <= n; i++) {
		im.erase(im.lower_bound({a[i], i}));	
		cout << im.find_by_order(n / 2 - 1)->first << '\n';	
		im.insert({a[i], i});
	}
}