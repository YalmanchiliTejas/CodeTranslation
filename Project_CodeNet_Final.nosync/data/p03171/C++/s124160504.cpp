#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 3004;
int dp[2][N][N], a[N];

int solve(int turn, int i, int j){
    if(i > j) 
        return 0;
    
    int &ans = dp[turn][i][j];
    if(ans != -1)
        return ans;
    
    if(turn){
        ans = max(a[i] + solve(turn ^ 1, i + 1, j), solve(turn ^ 1, i, j - 1) + a[j]);
    } else{
        ans = min(-a[i] + solve(turn ^ 1, i + 1, j), -a[j] + solve(turn ^ 1, i, j - 1));
    }
    return ans;
}

signed main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> a[i];
	}
	
	memset(dp, -1, sizeof(dp));
    cout << solve(1, 1, n);
	
	return 0;
}
