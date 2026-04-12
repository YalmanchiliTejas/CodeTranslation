#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
#define pi 3.141592653589793
#define mod 1000000007
#define pb push_back
#define all(v) v.begin(),v.end()
#define tc int t;cin>>t;while(t--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g int tt;cin>>tt;for(int ti=1;ti<=tt;ti++)
#define case_g "Case #"<<ti<<": "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

int main() {
	fast_io;
	ll n;
	cin >> n;
	vl a(n + 1);
	for (ll i = 1;i <= n;i++)
		cin >> a[i];
	vl dp(n + 1);
	vl odd(n + 1);
	dp[1] = max(a[1], 0LL);
	dp[2] = max(a[1], a[2]);
	odd[1] = a[1];
	for (int i = 3;i <= n;i++) {
		if (i & 1) {
			odd[i] = odd[i - 2] + a[i];
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		else {
			dp[i] = max(dp[i - 2] + a[i], odd[i - 1]);
		}
	}
	cout << dp[n] << '\n';
}
