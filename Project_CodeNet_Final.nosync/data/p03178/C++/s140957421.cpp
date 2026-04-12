#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int dp[100001][101][2];
string k;
int D;

int solve(int pos, int d, bool tight) {

	if (dp[pos][d][tight] != -1) return dp[pos][d][tight];
	int ub = (tight) ? (k[pos] - '0') : 9;
	if (pos == k.length() - 1) {
		int ans = 0;
		for (int x = 0; x <= ub; x++) {
			if (x % D == d) ans++;
		}

		return ans;
	}

	int ans = 0;
	for (int x = 0; x <= ub; x++) {
		ans = (ans + solve(pos + 1, (D + d - x % D) % D, tight && (x == ub))) % mod;
	}

	return dp[pos][d][tight] = ans;
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> k;
	cin >> D;

	memset(dp, -1, sizeof(dp));

	cout << (mod + solve(0, 0, 1) - 1) % mod;

	return 0;
}