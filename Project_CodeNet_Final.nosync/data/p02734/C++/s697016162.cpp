#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 3010
const ll mod = 998244353;
ll n, s, a[SIZE], dp[SIZE], ans;

int main() {
	 cin >> n >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)  {
		for (int j = s; j >= a[i]; --j) {
			dp[j] += dp[j - a[i]];
			dp[j] %= mod;
		}
		if (a[i] <= s) dp[a[i]] = (dp[a[i]] + i) % mod;
		ans = (ans + dp[s]) % mod;
		//for(int i=1;i<=s;i++) cout<<dp[i]<<" "; 
		//cout<<endl;
	}	
	cout << ans;
}