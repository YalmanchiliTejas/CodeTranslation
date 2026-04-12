#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;
const long long MAX = 2e9, INF = 1e18;

int n;
long long a[MAXN];
long long finalAns, sumL[MAXN][2], sumR[MAXN][2];
long long ans[MAXN][3];
bool found[MAXN][3];

long long dp(int pos, int rem){
	if(pos >= n)
		return (rem == 0) ? 0:-INF;
	if(found[pos][rem])
		return ans[pos][rem];
	found[pos][rem] = true;
	ans[pos][rem] = dp(pos+2, rem)+a[pos];
	if(rem > 0)
		ans[pos][rem] = max(ans[pos][rem], dp(pos+1, rem-1));
	return ans[pos][rem];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
		a[i] += MAX;
	}
	if(n%2 == 0){
		finalAns = max(dp(0, 0), dp(0, 1));
	}else{
		finalAns = max(dp(0, 1), dp(0, 2));
	}
	printf("%lld\n", finalAns-(MAX*(n/2)));
}