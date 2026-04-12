#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define cast static_cast
#define vi vector<int>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e11;

void solve(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	v<v<ll>> dp(n,v<ll>(n+1));
	for(int i=n-1;i>=0;i--){
		for(int j=1;i+j-1<n;j++){
			if(j==1){
				dp[i][j]=a[i];
			}
			else{
				dp[i][j]=max(a[i+j-1]-dp[i][j-1],a[i]-dp[i+1][j-1]);
			}
		}
	}
	cout<<dp[0][n]<<"\n";
}

int main(){
	solve();
	return 0;
}