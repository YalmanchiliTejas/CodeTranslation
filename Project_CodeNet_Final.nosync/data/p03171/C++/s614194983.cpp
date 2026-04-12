#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3005][3005];

ll solve(ll a[], int start, int end, bool isfirst){
	if(start > end)
		return 0;
		
	if(start==end)
		return a[start];
	
	if(start+1 == end) {
		if(isfirst || true)
			return max(a[start], a[end]);
		else
			return min(a[start], a[end]);
	}
	
	if(dp[start][end] != -1)
		return dp[start][end];
	
	ll ans=0;	
	
	ans=max( a[start] + min( solve(a, start+2, end, false), solve(a, start+1, end-1, false) ) , a[end] + min( solve(a, start+1, end-1, false), solve(a, start, end-2, false) ) );
	
	return dp[start][end] = ans;
}

void solve(){
	int n;
	cin >> n;
	
	ll a[n]={};
	long long int tot=0;
	
	for(int i=0; i<n; i++) {
		cin >> a[i];
		tot+=a[i];
	}
		
	
	memset(dp, -1, sizeof dp);
			
	// [X-Y] maximize means max X, minimize means min X
	
	ll x = solve(a, 0, n-1, true);
	ll y = tot-x;
	
	cout << x-y << "\n";
}

int main(){
	solve();
}
