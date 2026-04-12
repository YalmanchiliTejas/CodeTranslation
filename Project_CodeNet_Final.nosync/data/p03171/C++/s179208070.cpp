#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;


int n ;
int a[3010];
int dp[3010][3010][2];

int solve(int i , int j , int t ) {

	if (i > j)return 0;

	if (dp[i][j][t] != -1)return dp[i][j][t];

	if (t == 1)return dp[i][j][t] = max(a[i] + solve(i + 1 , j , 0) , a[j] + solve(i , j - 1 , 0));

	if (t == 0)return dp[i][j][t] = min(solve(i + 1 , j , 1) , solve(i , j - 1 , 1));

}

int32_t main() {

	fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif

	memset(dp , -1 , sizeof(dp));
	cin >> n;
	for (int i = 1 ; i <= n ; i++)cin >> a[i];

	int x = solve(1, n , 1);
	int sum = 0;
	for (int i = 1 ; i <= n  ; i++)sum += a[i];

	int y = sum - x;

	cout << x - y;



	return 0;
}
