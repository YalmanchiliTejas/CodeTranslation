/*
ID: seekho
PROG: friday
LANG: C++14                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

//find_by_order gives kth-largest element
//order_of_key gives the number of items in the set that are strictly smaller!!

// OT.find_by_order(k-1)
// 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define db4(x, y, z, w) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #w << "=" << w << endl
#define ll long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define X first
#define Y second
#define sz(x) (int)((x).size())
#define pii pair<int,int>
#define MOD (ll)(1e9 + 7)
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
#define inf (ll)(1e18)
#define double long double
#define int long long

//////////////////////
const int N = 3005;
int n;
vector<int> arr(N);
int memo[N][N];
vector<int> fa;
vector<int> fb;

int go(int st, int end, int ch, int ta, int tb) {
	if(end < st) {
		return 0;
	}

	int &ans = memo[st][end];
	if(ans != -inf)
		return ans;
	ans = 0;

	if(!ch) {
		// ans = -inf;
		// ans = max(go(st + 1, end, !ch, ta + arr[st], tb), go(st, end - 1, !ch, ta + arr[end], tb));
		ans = go(st, end - 1, !ch, ta, tb) + arr[end];
		// db(sz(fa));
		// fa.pb(arr[end]);
		if(ans < go(st + 1, end, !ch, ta, tb) + arr[st]) {
			ans = go(st + 1, end, !ch, ta, tb) + arr[st];
			// fa.pop_back();
			// db(sz(fa));
			// fa.pb(arr[st]);
		}
		// else {
		// 	ans = go(st, end - 1, !ch, ta + arr[end], tb);
		// 	fa.pb(arr[end]);
		// }

	}
	else {
		// ans = inf;
		// ans = min(go(st + 1, end, !ch, ta, tb + arr[st]), go(st, end - 1, !ch, ta, tb + arr[end]));
		ans = go(st, end - 1, !ch, ta, tb) - arr[end];
		// fb.pb(arr[end]);
		if(ans > go(st + 1, end, !ch, ta, tb) - arr[st]) {
			ans = go(st + 1, end, !ch, ta, tb) - arr[st];
			// fb.pop_back();
			// fb.pb(arr[st]);
		}
	
	}
	return ans;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    // cout.precision(12);cout << fixed;

    cin >> n;
    rep(i,n)
    	cin >> arr[i];

    rep(i,n) {
    	rep(j,n) 
    		memo[i][j] = -inf;
    }

    cout << go(0,n-1,0,0,0) << '\n';
}