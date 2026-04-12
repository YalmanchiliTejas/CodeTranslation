#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
ll n, dp[3005][3005];
const ll inf = 1e18+5;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	vector<ll> a(n);
	for (ll i= 0; i< n; i++)cin >> a[i];
	for (ll i = n-1; i >= 0; i--){
		for (ll j = i; j < n; j++){
			ll L = i, R= j;
			dp[i][j] = max(a[L] - dp[L+1][R], (R == 0 ? -inf:a[R] - dp[L][R-1]));
		}
	}
	cout << dp[0][n-1];
}
