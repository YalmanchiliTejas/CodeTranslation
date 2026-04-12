#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
const int maxn = 200000 + 10;
Tree<pii> t;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]); 
		t.insert(mp(a[i], i));
	}
	for(int i = 1; i <= n; ++i)
	{
		t.erase(mp(a[i], i));
		printf("%d\n", t.find_by_order(n / 2 - 1)->first);
		t.insert(mp(a[i], i));
	}
	return 0;
}
		 