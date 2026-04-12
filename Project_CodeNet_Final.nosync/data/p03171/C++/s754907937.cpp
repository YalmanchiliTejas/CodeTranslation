#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
 
ll n,p[3100],dp[3100][3100];

ll rek(int l, int r) {
	
	//printf("%d %d\n",l,r);
	
	if(l == r) return 0;
	
	if(dp[l][r] != -1) return dp[l][r];
	
	return dp[l][r] = max(p[l] - rek(l + 1,r), p[r - 1] - rek(l, r - 1));
}

int main() {
	
	scanf("%lld", &n);
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &p[i]);
	}
	
	printf("%lld",rek(0,n));
	
	return 0;
}
		