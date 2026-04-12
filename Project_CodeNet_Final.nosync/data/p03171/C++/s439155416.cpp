//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
#define MAX 3011
#define mod 1000000007
#define inf 1000000000000000000
#define ll long long
#define endl '\n'
int n;
ll dp[MAX][MAX][2],a[MAX];
ll memo(int i,int j,bool b){
	if(i == j){
		if(!b) return a[i];
		else return -a[i];
	}

	if(dp[i][j][b] != inf)return dp[i][j][b];
	
	if(!b)
		dp[i][j][0] = max(memo(i + 1, j,1) + a[i],memo(i,j-1,1) + a[j]);
	else
		dp[i][j][1] = min(memo(i + 1, j,0) - a[i],memo(i,j-1,0) - a[j]);
	
	return dp[i][j][b];
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0; i < n ; i++)cin>>a[i];
	
	for(int i = 0; i < n ; i++)
		for(int j =0 ; j < n; j++)
			dp[i][j][0] = dp[i][j][1] = inf;
	
	cout<<memo(0,n-1,0);
	return 0; 
} 