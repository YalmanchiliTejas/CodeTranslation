#include <bits/stdc++.h>
using namespace std;

int n;
long long a[3005];
long long dp[3005][3005];

long long f(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];
    if(x == y) return dp[x][y] = a[x];
    
    long long p = a[x] - f(x+1, y);
    long long q = a[y] - f(x, y-1);
    
    return dp[x][y] = max(p, q);
}

int main() {
	// your code goes here
	cin >> n;
	for(int i = 0; i < n; i++) {
	    cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << f(0, n-1);
	return 0;
}
