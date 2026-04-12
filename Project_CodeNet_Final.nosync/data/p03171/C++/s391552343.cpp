#include <bits/stdc++.h>
#define N 3001
using namespace std;
typedef long long ll;

int n, a[N];
ll dp[N][N][2];

ll f(int i, int j, int k) {
	if (i==j-1) return 0;
	if (dp[i][j][k]!=0) return dp[i][j][k];

	if (k==0) {
		dp[i][j][0] = max(
			f(i+1,j,1)+a[i+1],
			f(i,j-1,1)+a[j-1]
		);
	} else {
		dp[i][j][1] = min(
			f(i+1,j,0)-a[i+1],
			f(i,j-1,0)-a[j-1]
		);
	}
	return dp[i][j][k];
}

int main() {
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	cout<<f(0,n+1,0)<<endl;
	return 0;
}