#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,lessl<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define int long long
#define double long double

#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()

#define ff first
#define ss second
#define mp make_pair

#define pb push_back
#define endl "\n"

#define f(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,r,l) for(int i=r;i>=l;i--)

#define bp __builtin_popcountll
#define inf 1e18

const int N = 1e5 + 5;
const int M = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	if (n >= 30)
		cout << "Yes";
	else
		cout << "No";
}

signed main()
{
	FAST

#ifndef ONLINE_JUDGE
	freopen("input_sublime.txt", "r", stdin);
	freopen("output_sublime.txt", "w", stdout);
#endif

	int t = 1;
	// cin>>t;
	for (int tc = 1; tc <= t; tc++)
	{
		// cout<<"Case #"<<tc<<": ";
		solve();
	}

#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
