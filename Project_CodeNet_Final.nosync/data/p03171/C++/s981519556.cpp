#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define INF (ll) (1e9)
#define mod (ll) (1e9 + 7)
#define endl "\n"
#define tt ll testcase; cin>>testcase; while(testcase--)
 
const int mxn = 1*(1e5) + 5;
ll n, m;
 
void solve(){
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++) cin >> a[i];

	ll dp[n][n] = {};
	for(int l=n-1; l>=0; l--) {
		for(int r=l; r<n; r++) {
			if(r == l) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
			}
		}
	}
	cout << dp[0][n-1];
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
	// tt
		solve();
	return 0;
}