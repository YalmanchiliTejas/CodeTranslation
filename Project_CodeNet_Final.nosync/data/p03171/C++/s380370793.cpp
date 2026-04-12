#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define INF (ll) 1e9
#define tt ll testcase; cin>>testcase; while(testcase--)
 
int main(){
	fast;
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	ll dp[n][n]={};
	for(ll l=n-1; l>=0; l--){
		for(ll r=l; r<n; r++){
			if(l==r){
				dp[l][r] = a[l];
			}
			else{
				dp[l][r] = max( a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
			}
		}
	}
	cout<<dp[0][n-1];
}