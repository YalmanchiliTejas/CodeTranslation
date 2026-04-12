#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;	

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const ll maxN = 3e3 + 5;
const ll MOD = 998244353;

int n, k;
ll dp[maxN][maxN], pref[maxN], pref2[maxN];
int arr[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	RI(i, n) {
		cin >> arr[i];
	}
	dp[0][0] = 0;
	// dp[i][s] - suma lewych koncow o sumie s konczy sie na i
	RI(i, n) {
		dp[i][arr[i]] = i;
		FOR(j, arr[i] + 1, k) {
			dp[i][j] = pref[j - arr[i]];
			pref2[j] = (pref[j] + dp[i][j]) % MOD;
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
		pref[arr[i]] = (pref[arr[i]] + i) % MOD;
		FOR(j, arr[i] + 1, k) pref[j] = pref2[j];
	}
	ll ans = 0;
	RI(i, n) {
		ans = (ans + (ll)(n - i + 1) * dp[i][k]) % MOD;
	}	
	cout << ans << endl;
	return 0;
}
 
