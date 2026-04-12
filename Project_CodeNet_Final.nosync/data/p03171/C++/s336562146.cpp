/**
 *   author: Shubham Srivastava
 *   created: 27 January 2020  20:35:16
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007
#define INF 0x7fffffff
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.rbegin(),v.rend())
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
ll parent[2000005];

ll helper(vector <ll> &arr, ll sum, ll i, ll j, vector <vector <ll> > &dp){
	if(i > j)
		return 0;
	if(i == j)
		return arr[j];
	if(i+1 == j)
		return max(arr[i],arr[j]);
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(sum - helper(arr,sum-arr[i],i+1,j,dp), sum - helper(arr,sum-arr[j],i,j-1,dp));
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n;cin>>n;
    ll sum = 0;
    vector <ll> arr(n);
    vector <vector <ll> > dp(n, vector <ll> (n,-1));
    for(int i=0;i<n;i++){
    	cin>>arr[i];    
    	sum += arr[i];
    }
    ll val1 = helper(arr,sum,0,n-1,dp);
    ll val2 = sum - val1;
    cout<<val1-val2;
return 0;
}