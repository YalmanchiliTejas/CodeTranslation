#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,m,n) for(ll i=ll(m); i<ll(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;



int main() {



	int n;
	cin >> n;

	VLL a(n);
	REP(i, n)cin >> a[i];

	if (n <= 3) {
		sort(ALL(a));
		reverse(ALL(a));
		cout << a[0] << endl;
		return 0;
	}

	if (n % 2 == 0) {
		VVLL dp(n, VLL(2, 0));
		dp[0][0] = a[0];
		dp[1][1] = a[1];
		FOR(i, 2, n) {
			if (i % 2 == 0)dp[i][0] = dp[i - 2][0] + a[i];
			else {
				dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
			}
			
		}
		cout << max(dp[n - 1][1], dp[n - 2][0]) << endl;
		return 0;
	}

	VVLL dp(n, VLL(4, -INFL));
	dp[0][0] = a[0];
	dp[1][1] = a[1];
	dp[2][2] = a[2];
	dp[2][0] = dp[0][0] + a[2];
	FOR(i, 3, n) {

		if (i % 2 == 0) {
			dp[i][0] = dp[i - 2][0] + a[i];
			dp[i][2] = max({ dp[i - 2][2],dp[i - 3][1],dp[i - 4][0] }) + a[i];
		}
		else {
			dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
		}
	}
	ll ans = max({ dp[n - 1][2],dp[n - 2][1],dp[n - 3][0]});

	VVLL dq(n + 100, VLL(3, -INFL));
	dq[0][0] = a[0];
	FOR(i,1, n) {
		if (i % 2 == 0)dq[i][0] = dq[i - 2][0] + a[i];
	}

	dq[3][1] = a[0] + a[3];
	
	FOR(i, 5, n) {
		if (i % 2 == 1) {
			dq[i][1] = max(dq[i - 2][1], dq[i - 3][0]) + a[i];
		}
		else {
			if (i < 6)continue;
			dq[i][2] = max(dq[i - 2][2], dq[i - 3][1]) + a[i];
		}
	}

	ans = max(ans, dq[n - 1][2]);
	ans = max(ans, dq[n - 2][1]);

	cout << ans << endl;
}