#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;

void solve(){
	int n;
	cin>>n;
	vector<lli> a(n+1);
	for(int i=1;i<n+1;i++){
		cin>>a[i];
	}
	vector<lli> dp(n+1,0);
	dp[1] = 0;
	vector<lli> prefix(n+1);
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
	cout<<dp[n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();//checking
    return 0;
}