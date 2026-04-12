#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
 
int n, m;
char S[200005];
vector<int> sizs;
int dp[200005], prs[200005];

int main()
{
	scanf("%d%d%s", &n, &m, S);
	
	int ccnt = 1;
	for(int i = 1; i < m; i ++)
	if(S[i] != S[i - 1]) {
		sizs.push_back(ccnt);
		ccnt = 1;
	} else ccnt ++;
	sizs.push_back(ccnt);
	
	if(sizs.size() == 1) {
		dp[1] = 2;
		dp[2] = MOD - 1;
		rep(i, n) {
			if(i >= 1) dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}
		rep(i, n) {
			if(i >= 1) dp[i] = (dp[i] + dp[i - 1]) % MOD;
			if(i >= 2) dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
		printf("%d\n", dp[n - 1] + 1);
	} else {
		int maxl = min(n, sizs[0] + 2);
		rep(i, sizs.size()) if(i + 1 < sizs.size() && !(i & 1) && (sizs[i] & 1))
		maxl = min(maxl, sizs[i] + 1);
		
		rep1(i, maxl) if(!(i & 1)) dp[i] = i;
		
		rep1(i, n) {
			if(i >= 2) dp[i] = (dp[i] + prs[i - 2]) % MOD;
			if(i >= 2 + maxl) dp[i] = (dp[i] + (MOD - 1LL) * prs[i - 2 - maxl]) % MOD;
			if(i >= 2) prs[i] = (dp[i] + prs[i - 2]) % MOD;
		}
		
		printf("%d\n", dp[n]);
	}
	return 0;
}