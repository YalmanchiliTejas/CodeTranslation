#include<bits/stdc++.h>
using namespace std;
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define ll long long
#define mod 998244353 
#define pb push_back
#define mb make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
	IOS;
	ll n ; cin >> n;
	pair<ll,ll> dp[n+1][n+1];
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++)
			dp[i][j].first= 0, dp[i][j].second = 0;

	ll arr[n+1];
	for(ll i=1;i<=n;i++) 	cin >> arr[i];
	for(ll i=1;i<=n;i++)
		dp[i][i].first = arr[i];


	for(ll l =2 ; l<=n ; l++){
		for(ll left = 1 ; left <= n-l+1 ; left++){
			ll right = left+l-1;
			// cout << left << " " << right << endl;	
			if(arr[left]+dp[left+1][right].second > arr[right]+dp[left][right-1].second){
				dp[left][right].first = arr[left]+dp[left+1][right].second;
				dp[left][right].second = dp[left+1][right].first;
			}
			else{
				dp[left][right].first = arr[right]+dp[left][right-1].second;
				dp[left][right].second = dp[left][right-1].first;
			}


			// dp[left][right].first = max(arr[left]+dp[left+1][right].second,arr[right]+dp[left][right-1].second);
			// dp[left][right].second = min(arr[left]+dp[left+1][right].second,arr[right]+dp[left][right-1].second);
		}
	}
	// for(ll i=1;i<=n;i++){
	// 	for(ll j=1;j<=n;j++)
	// 		cout << dp[i][j].first << "," << dp[i][j].second << " ";
	// 	cout << endl;
	// }
	cout << dp[1][n].first - dp[1][n].second << endl;


	return 0;
}


