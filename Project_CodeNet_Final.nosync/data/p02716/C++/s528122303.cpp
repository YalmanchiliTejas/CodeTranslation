#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int mxn = 2e5 + 1;
ll arr[mxn], dp[mxn], pref[mxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i = 1; i<=n; ++i) cin>>arr[i];
	dp[0] = 0;
	pref[0] = 0;
	pref[1] = arr[1];
	for(int i = 2; i <=n; ++i) pref[i] = pref[i-2] + arr[i];
	dp[1] = 0;
	for(int i = 2; i <=n; ++i){
		if(i&1){
			dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
		} else{
			dp[i] = max(dp[i-2] + arr[i], pref[i-1]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

