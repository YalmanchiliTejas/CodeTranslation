#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5,INF = 0xfeeddeadbeef,inf = INF >> 1;
int n,a[N];
map<int,int> dp[N];
int DP(int i,int k) {
	if(k > (i+1>>1)) return -inf;
	if(i <= 0) return 0;
	if(dp[i][k]) return dp[i][k];
	return dp[i][k] = max(DP(i-2,k-1) + a[i],DP(i-1,k));
}
signed main() {
	cin >> n;
	for(int i = 1;i <= n;++i)	
		cin >> a[i];
	cout << DP(n,n>>1) << endl;
	return 0;
}
