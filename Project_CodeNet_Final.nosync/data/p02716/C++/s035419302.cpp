#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

ll dp[200010][2][3];

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for( auto &k : a ) cin >> k;
	dp[0][1][0] = a[0];
	dp[0][0][0] = 0;
	for( int i = 1; i < n; ++i ){
		dp[i][1][0] = dp[i-1][0][0] + a[i];
		dp[i][1][1] = dp[i-1][0][1] + a[i];
		dp[i][1][2] = dp[i-1][0][2] + a[i];
		dp[i][0][0] = dp[i-1][1][0];
		dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][1][1]);
		dp[i][0][2] = max(dp[i-1][0][1], dp[i-1][1][2]);
	}
	if( n%2 == 0 ) cout << max(dp[n-1][1][1], dp[n-1][0][0]) << endl;
	else cout << max(dp[n-1][0][1], dp[n-1][1][2]) << endl;
}