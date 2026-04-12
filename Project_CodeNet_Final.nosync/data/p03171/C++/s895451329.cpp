/*input
4
10 80 90 30
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
int a[3001];
int dp[3001][3001][2];
int solve(int i,int j,int turn){
	if(i == j){
		if(turn == 0){
			return a[i];
		}
		return -a[i];
	}
	if(dp[i][j][turn]){
		return dp[i][j][turn];
	}
	if(turn == 0 ){
		return dp[i][j][turn]=max(a[i]+solve(i+1,j,!turn),a[j]+solve(i,j-1,!turn));
	}
	else{
		return dp[i][j][turn]=min(-a[i]+solve(i+1,j,!turn),-a[j]+solve(i,j-1,!turn));
	}
}
signed main() {
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout << solve(0,n-1,0) << endl;
return 0;
}
