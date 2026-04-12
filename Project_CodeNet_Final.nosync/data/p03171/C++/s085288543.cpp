/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 25 May 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
#define endl '\n'

int n;
vector<ll> arr;
ll dp[3001][3001][2];

ll fun(int st, int end, bool player){

	if(st == end){
		if(player==0){
			return arr[st];
		}
		else{
			return -arr[st];
		}
	}

	if(dp[st][end][player] != -1) return dp[st][end][player];

	if(player == 0){
		if(dp[st+1][end][player^1] == -1){	
			dp[st+1][end][player^1] = fun(st+1, end, player^1);
		}
		if(dp[st][end-1][player^1] == -1){
			dp[st][end-1][player^1] = fun(st, end-1, player^1);
		}
		return dp[st][end][player] = max(arr[st] + dp[st+1][end][player^1], arr[end] + dp[st][end-1][player^1]);
	}
	else{
		if(dp[st+1][end][player^1] == -1){
			dp[st+1][end][player^1] = fun(st+1, end, player^1);
		}
		if(dp[st][end-1][player^1] == -1){
			dp[st][end-1][player^1] = fun(st, end-1, player^1);
		}
		return dp[st][end][player] = min(-arr[st] + dp[st+1][end][player^1], -arr[end] + dp[st][end-1][player^1]);
	}

}

signed main(){

    fastio;
    memset(dp, -1, sizeof(dp));

    cin>>n;
    arr = vector<ll>(n);

    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    // 0-> Player X, 1-> Player Y
    cout<<fun(0,n-1,0);

    return 0;

}