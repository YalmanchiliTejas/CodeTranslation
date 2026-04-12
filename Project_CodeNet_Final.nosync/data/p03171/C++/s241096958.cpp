#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define ll long long int 
#define gof for(long long int i = 0 ; i < n ; i++)
#define for1(i,s,e) for(long long int i = s ; i < e ; i++)
#define mkar(a,n) long long int *a = NULL; a = new long long int [n];

ll dp[3001][3001][2];
ll a[3000];
ll solve(ll i, ll j, ll who){

	if(i>j){
		return 0;
	}

	if(dp[i][j][who] != -1){
		return dp[i][j][who];
	}

	if(who == 0){
		dp[i][j][who] = max(solve(i+1,j,who+1)+a[i],solve(i,j-1,who+1)+a[j]);
	}

	else{
		dp[i][j][who] = min(solve(i + 1, j, who - 1) - a[i], solve(i, j - 1, who - 1) - a[j]);
	}

	return dp[i][j][who];
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	for1(i,0,3001){
		for1(j,0,3001){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
	ll n;
	cin >> n;
	gof cin >> a[i];
	cout << solve(0,n-1,0) << endl;
	return 0;
}