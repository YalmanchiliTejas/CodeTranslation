#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define LONGMAX 1e18
#define MOD 1000000007
#define mp make_pair
#define endl "\n"
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
#define fastio()  ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
	#endif
	fastio()
	
	int n;
	cin>>n;
	vector<int> arr(n,-1);
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];

	//creating 2D DP table where dp[i][j] denotes the scores of 
	// taro and jiro with arr i to j

	vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(n,{0,0}));
	//first element of pair is taros score and second is jiros.

	//base case is arrays with one element
	for(int i = 0 ; i < n ; i++)
		dp[i][i].first = arr[i];

	for(int size = 1 ; size < n ; size++){
		for( int i = 0 ; i + size < n ; i++){
			int j = i + size;
			ll pickright = arr[j] + dp[i][j-1].second; 
			ll pickleft = arr[i] + dp[i+1][j].second;
			if(pickleft > pickright){
				dp[i][j].first = pickleft;
				dp[i][j].second = dp[i+1][j].first;
			}else{
				dp[i][j].first = pickright;
				dp[i][j].second = dp[i][j-1].first;
			}
		}
	}
	cout<<dp[0][n-1].first - dp[0][n-1].second<<endl;
}
