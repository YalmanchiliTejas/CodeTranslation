#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 998244353;
const int N = 3005;
int a[N];
ll dp[N][N], sdp[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, s;
	cin>>n>>s;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	memset(dp, 0, sizeof(dp));
	memset(sdp, 0, sizeof(sdp));
	for(int i = 1; i <= n; i++){
		dp[i][a[i]] = i;
		for(int sum = a[i] + 1; sum <= s; sum++){
			dp[i][sum] = sdp[i - 1][sum - a[i]];
		}
		for(int sum = 0; sum <= s; sum++){
			sdp[i][sum] = sdp[i - 1][sum] + dp[i][sum];
			if(sdp[i][sum] >= mod)sdp[i][sum] -= mod;
		}
	}
	// for(int i = 1; i <= n; i++){
	// 	for(int sum = 0; sum <= s; sum++){
	// 		cout<<dp[i][sum]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (n - i + 1)*dp[i][s];
		ans %= mod;
	}
	cout<<ans<<endl;

	return 0;
}