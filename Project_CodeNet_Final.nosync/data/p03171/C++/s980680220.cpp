#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9

//dp[i][j] - answer for that state(min or max)
int main(){
	int n;cin>>n;
	// if(n==0) cout<<0
	vector<ll> v(n);
	vector<ll> pref(n+1,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		pref[i+1] = pref[i]+v[i];
	}
	// bool state = n%2==0; //when even T moves else K moves
	vector<vector<ll> > dp(n,vector<ll>(n,0));
	ll ans2=0;
	for(int d=0;d<n;d++){
		for(int i=0;i<n-d;i++){
			int j = i+d;
			if(j==i) {dp[i][j] = v[i];continue;}
			ll tot_sum = pref[j+1] - pref[i];
			assert(i+1<n&&j-1>=0);
			dp[i][j] = tot_sum - min(dp[i+1][j],dp[i][j-1]);
			if(d==n-1) ans2 = min(dp[i+1][j],dp[i][j-1]);
		}
	}
	cout<< (dp[0][n-1]-ans2) << endl;
	return 0;
}