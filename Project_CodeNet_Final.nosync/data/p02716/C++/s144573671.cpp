// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>

const int INF = 1e15 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int N = 2e5 + 5;

int Data[N], n;
map <pii, int> dp;

int go(int ind, int req, int n) {
	if((n-ind+2)/2 < req) return -INF;
	if(ind > n || req == 0 ) return 0;
	if(dp.count({ind,req})) return dp[{ind, req}];
	int temp1 = Data[ind] + go(ind+2, req-1, n);
	int temp2 = go(ind+1,req, n);
    return (dp[{ind, req}] = max(temp1, temp2));
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //  // freopen("output.txt", "w", stdout);
    // #endif
    cin >> n;
	for(int i = 1; i <= n; i++) cin >> Data[i];
	cout << go(1, n/2, n) << '\n';
}

