#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 

// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

# define ll long long int
#define M 1000000007
#define pb push_back
#define ss second
#define ff first
#define inf 1000000000000000


 

													//nestedcode



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,i,ans = 0;
    cin>>n;
    ll a[n+5], dp[n+5];
    for(i=0;i<n;i++){
    	cin>>a[i];
    	if(i == 0)
    	dp[i] = a[i];
    	else
    	dp[i] = dp[i-1] + a[i];
	}
	for(i=1;i<n;i++){
		ans += (dp[i-1]%M * a[i]%M)%M;
		ans %= M;
	}
	cout<<ans<<endl;
}
