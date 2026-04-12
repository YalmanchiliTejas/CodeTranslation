#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 998244353
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n, s;
	cin >> n >> s;
	
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	vvi dp(n + 1, vi(s + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= s; j++) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % P;
		for(int j = 0; j < s; j++) if(j + a[i - 1] <= s) dp[i][j + a[i - 1]] = (dp[i][j + a[i - 1]] + (dp[i - 1][j] * (j == 0 ? i : 1)) % P) % P;
		
		ans = (ans + dp[i][s]) % P; 
	}
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}