#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5,INF = 0x7ffffffddeadbeef,inf = INF >> 1;
int n,a[N];
map<int,ll> dp[N];
ll DP(int i,int k) {
	if(k > (i+1>>1)) return -inf;
	if(i <= 0||k==0) return 0;
	if(dp[i].count(k)) return dp[i][k];
	return dp[i][k] = max(DP(i-2,k-1) + a[i],DP(i-1,k));
}
int main() {
	cin >> n;
	for(int i = 1;i <= n;++i)	
		cin >> a[i];
	cout << DP(n,n>>1) << endl;
	return 0;
}
