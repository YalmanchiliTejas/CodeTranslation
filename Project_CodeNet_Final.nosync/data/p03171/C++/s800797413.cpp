#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define cBits(x) __builtin_popcount(x)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) a/gcd(a,b)*b
#define FOR(i,a,b) for (int i=a;i<b;i++)
#define FORr(i,a,b) for (int i=a;i>=b;i--)
#define MAX3(a,b,c) max(a,max(b,c))
#define MIN3(a,b,c) min(a,min(b,c))
#define eachTest int t; cin >> t; while(t--) solve();

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;

const int MOD=1000000007;

void solve() {
	;
}

int main() {

	fastio;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	// eachTest

	int n;
	cin >> n;
	vector <ll> arr(n);
	FOR(i,0,n) {
		cin >> arr[i];
	}
	ll sum[n][n];
	FOR(i,0,n) {
		sum[i][i] = arr[i];
	}
	FOR(i,0,n) {
		FOR(j,i+1,n) {
			sum[i][j] = sum[i][j-1] + arr[j];
		}
	}
	// FOR(i,0,n) {
	// 	FOR(l,2,n+1) {
	// 		int j = i+l-1;
	// 		if (j > n) {
	// 			break;
	// 		}
	// 		sum[i][j] = sum[i][j-1] + arr[j];
	// 	}
	// }
	ll table[n][n];
	FOR(i,0,n) {
		table[i][i] = arr[i];
	}
	FOR(l,2,n+1) {
		FOR(i,0,n) {
			int j = i+l-1;
			if (j >= n) {
				break;
			}
			table[i][j] = max(arr[i] + sum[i+1][j]-table[i+1][j], arr[j] + sum[i][j-1]-table[i][j-1]);
		}
	}

	cout << 2*table[0][n-1] - sum[0][n-1];

	return 0;
}
