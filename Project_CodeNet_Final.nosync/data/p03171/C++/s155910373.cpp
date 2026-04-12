#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
ll dp[3005][3005][2];
ll v[3005];
bool mark[3005][3005][2];
 
ll f(int l, int r, int p) {
	if(l == r) return v[l];
	if(mark[l][r][p]) return dp[l][r][p];
	mark[l][r][p] = true;
 
	ll ret = max(-f(l+1, r, p^1) + v[l], -f(l, r-1, p^1) + v[r]);
	return dp[l][r][p] = ret;
}
 
int main() {
	int n;
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++)
		scanf("%lld", &v[i]);
 
	printf("%lld\n", f(1,n,0));
	
    return 0;
}