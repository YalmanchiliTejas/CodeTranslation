#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long
int dp[3001][3001][2];

int deq(int i, int j, vector<int> &a, int turn){
	if(i > j)return 0;
	if(dp[i][j][turn] != -1)return dp[i][j][turn];

	if(turn == 0){
		dp[i][j][turn] = max(a[i]+deq(i+1,j,a,1),a[j]+deq(i,j-1,a,1));
	}
	else{
		dp[i][j][turn] = min(deq(i+1,j,a,0),deq(i,j-1,a,0));
	}
	return dp[i][j][turn];
}

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	int i;
	for(i=0;i<n;i++)cin>>a[i];
	int j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<2;k++)dp[i][j][k] = -1;
		}
	}
	int x = deq(0,n-1,a,0);
	int sum = 0;
	for(i=0;i<n;i++)sum += a[i];
	int y = sum - x;
	
	cout<<x-y<<endl;
	return;
}

int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}
