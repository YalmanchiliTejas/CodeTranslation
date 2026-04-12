#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long int
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define ub upper_bound
#define lb lower_bound
#define present(c,x) (c.find(x) != c.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define endl '\n'	
#define fill(s,x,n) vector<s> x(n); rep(i,0,n) cin>>x[i];
#define INF 1000000007 
#define MOD 998244353
#define INF64 1e18

void solve(){
	int n;
	cin>>n;
	fill(int,a,n);

	int sum=0;
	vector<vector<int>> dp(n,vector<int> (n));

	rep(len,1,n+1){
		rep(i,0,n-len+1){
			int j=i+len-1;
			if(len==1){
				dp[i][j]=a[i];
				sum+=a[i];
			}
			else if(len==2)
				dp[i][j]=max(a[i],a[j]);
			else
				dp[i][j]=max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}

	cout<<2*dp[0][n-1]-sum;
}	
 
int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
 
	int T;
	// cin>>T;
	T=1;
	while(T--){
		solve();
	}
}