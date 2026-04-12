#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long int
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
int a[3000];
int dp[3000][3000];

void play(int i, int j, int p = 1) {
	if (i == j) {
		if (p&1)
			dp[i][j] = a[i];
		return;
	} else if (dp[i][j] != 0) {
		return;
	}
	play(i + 1, j, p^1);
	play(i, j - 1, p^1);
	if (p&1) {
		int s1 = a[i] + dp[i+1][j];
		int s2 = a[j] + dp[i][j-1];
		dp[i][j] = max(s1, s2);
	} else {
		dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
	}
}

void solve() {
	int su = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	su += a[i];
    }
    play(0, n-1);
    // for (int i = 0; i < n; i++) {
    // 	for (int j = 0; j < n; j++) {
    // 		cout << i << " " << j << " " << dp[i][j] << endl;
    // 	}
    // }
    cout << 2*dp[0][n-1] - su;
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}