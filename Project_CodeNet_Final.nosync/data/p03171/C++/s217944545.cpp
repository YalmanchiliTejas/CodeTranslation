#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define N 1000000007
#define pll pair<ll,ll>
#define fill_nums(A,n) for(int i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(int i=0;i<m;i++) {int a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(int i=0;i<m;i++) {int a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}

int main() {
    
	ll n; cin>>n;
	vector<ll> A(n,0);

	fill_nums(A,n);
	vector<vector<pll>> dp(n, vector<pll>(n,{0,0}));

	for(int i=n-1;i>=0;i--) {
		for(int j=i;j<n;j++) {
			dp[i][j].first = max((i+1<n ? dp[i+1][j].second : 0) + A[i], (j-1>=0 ? dp[i][j-1].second : 0) + A[j]);
			if(i==n-1) dp[i][j].second=0;
			else dp[i][j].second = min((i+1<n ? dp[i+1][j].first : INT_MAX), (j-1>=0 ? dp[i][j-1].first : INT_MAX));
		}
	}

	cout<<dp[0][n-1].first-dp[0][n-1].second<<endl;

    return 0;
}


