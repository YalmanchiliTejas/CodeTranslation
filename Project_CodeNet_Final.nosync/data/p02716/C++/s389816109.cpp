//** aman**/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
void solve(){
	int n;
	cin>>n;
	vi a(n+1);
	rep(i,1,n+1){
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
	cout<<dp[n];
}
int main(){
    solve();
}
