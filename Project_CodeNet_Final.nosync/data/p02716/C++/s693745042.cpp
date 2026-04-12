#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i= 1; i <= n; ++i){
		cin>>a[i];
	}
	vector<ll> dp(n+1,0);
	dp[1] = 0;
	vector<ll> prefix(n+1);
	prefix[1] = a[1];
	for(int i=3;i<=n;i+=2){
		prefix[i] = prefix[i-2]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		}else{
			dp[i] = a[i] + dp[i-2];
			dp[i] = max(dp[i],prefix[i-1]);
		}
	}
	cout<<dp[n]<<endl;
}

int main() {
	//freopen("input.txt","r",stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	solve();

	/*if(){

		ll dp[n];
		fill(dp, dp+n, 0LL);

		// normal cases
		ll sum = 0;
		for(int i = 0; i < n; i += 2){
			sum += a[i];
		}
		ans = sum;
		sum = 0;
		for(int i = n-1; i >= 1; i -= 2){
			sum += a[i];
			dp[i] = sum;
		}
		ans = max(ans, sum);

		//abnormal case
		sum = 0;
		for(int i = 0; i+3 < n; i += 2){
			sum += a[i];
			ans = max(ans, sum + dp[i+3]);
		}
	}*/

}

