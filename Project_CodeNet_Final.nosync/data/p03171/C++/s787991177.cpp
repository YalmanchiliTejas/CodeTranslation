#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN = 3e3 + 13;
int n, a[maxN], dp[maxN][maxN];
int32_t main () {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    for (int dis = 0; dis < n; dis++)
	for (int i = 0; i + dis < n; i++) {
	    int j = i + dis;
	    if  (n % 2 == (j - i + 1) % 2) {
		if (j == i)
		    dp[i][j] = a[i];
		else
		    dp[i][j] = max(dp[i][j - 1] + a[j], dp[i + 1][j] + a[i]);
	    }
	    else {
		if (j == i)
		    dp[i][j] = -a[i];
		else
		    dp[i][j] = min(dp[i][j - 1] - a[j], dp[i + 1][j] - a[i]);
	    }
	}

    cout << dp[0][n - 1] << endl;
}
	    
