#include<iostream>
#include<bits/stdc++.h>
#define print(x) cout<<#x<<"="<<x<<'\n'
#define print2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define print3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define fr(i,a,n) for(int i=a;i<=(n);++i)
#define rf(i,a,n) for(int i=a;i>=(n);--i)
#define mp make_pair
#define mod 1000000007
#define eps 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vpii vector<pii>
using namespace std;

// ll game(vi a, int i, int j){
// 	if(i>j)
// 		return 0;
// 	if(i==j)
// 		return a[i];
// 	return max(a[i]+min(game(a,i+1,j-1),game(a,i+2,j)), a[j]+min(game(a,i+1,j-1),game(a,i,j-2)));

// }

int main() {
    int t=1;
    // cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	vi a(n);
    	ll sum=0;
    	rep(i,n){
    		cin>>a[i];
    		sum+=a[i];
    	}
    	// ll ans=game(a,0,n-1);
    	vvi dp(n+1, vi(n+1));
    	for(int gap=0;gap<n;gap++){
    		for(int i=0;i<n-gap;i++){
    			int j=i+gap;
    			ll x=0,y=0,z=0;
    			if(i+2<=j){
    				x=dp[i+2][j];
    			}
    			if(i+1<=j-1){
    				y=dp[i+1][j-1];
    			}
    			if(i<=j-2){
    				z=dp[i][j-2];
    			}
    			dp[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
    		}
    	}
    	// print(dp[0][n-1]);
    	cout<<dp[0][n-1]-sum+dp[0][n-1]<<endl;
    }
    return 0;
}