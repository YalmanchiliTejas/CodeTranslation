#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    ll v;
    scanf("%d",&n);
    vector<ll> a(n+1);
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i+1]);
    }

	vector<ll> dp(n+1,0);
	dp[1] = 0;
	// odd prefix
	vector<ll> prefix(n+1);
	prefix[1] = a[1];
	for(int i=3;i<=n;i+=2){
		prefix[i] = prefix[i-2]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		}else{
		    // two case when even
			dp[i] = a[i] + dp[i-2]; // select
			dp[i] = max(dp[i],prefix[i-1]); // or don't select, get all odd prefix
		}
	}
	cout<<dp[n];
}
