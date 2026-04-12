#include <bits/stdc++.h>
#define maxx 3010
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll dp[maxx][maxx][2];
ll arr[maxx];
int x;


ll solve(int i,int j,int p){
	if(i > j) return 0;
	if(dp[i][j][p] != -1e11) return dp[i][j][p];
	
	if(p == 0){
		return dp[i][j][p] = max(arr[i] + solve(i+1,j,1),arr[j] + solve(i,j-1,1)); 
	}
	else{
		return dp[i][j][p] = min(-arr[i] + solve(i+1,j,0), -arr[j] + solve(i,j-1,0) );
	}
}


int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);

	cin >> x;
	for(int i = 0; i < x; i++) cin >> arr[i];
		
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			dp[i][j][0] = -1e11;
			dp[i][j][1] = -1e11;
		}
	}
	cout << solve(0,x-1,0) << "\n";	
	return 0;
}