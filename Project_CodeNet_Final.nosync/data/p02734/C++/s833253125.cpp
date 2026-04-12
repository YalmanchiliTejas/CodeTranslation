#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define mp make_pair
#define pb push_back
#define VI vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const LL mod = 998244353;
bool mark[2][3010][3010];
LL memo[2][3010][3010];
int A[3010];
int n, s;
LL dp(int f, int p, int sum){
	if(sum == 0) return n - p + 1;
	if(p == n) return 0;
	LL& ans = memo[f][p][sum];
	if(mark[f][p][sum]) return ans;
	mark[f][p][sum] = true;
	ans = 0;
	if(!f) ans = dp(1, p, sum);
	(ans += dp(f, p+1, sum)) %= mod;
	if(f && sum - A[p] >= 0) (ans += dp(f, p+1, sum - A[p])) %= mod;
	return ans;
}
int main(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	printf("%lld\n", dp(0, 0, s));
	return 0;
}