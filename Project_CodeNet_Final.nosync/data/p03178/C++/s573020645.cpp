#include <bits/stdc++.h>
using namespace std;

int n;
char s[10055];
int d;

const int MOD = 1e9 + 7;

int dp[10055][155][2];

inline void add(int &a, int b) {
	a += b;
	
	if (a >= MOD) {
		a -= MOD;
	}
}
int rec(int id, int rem, int less) {
	if (id == n) {
		return rem == 0;
	}
	if (dp[id][rem][less] >= 0) return dp[id][rem][less];
	
	int res = 0;
	
	for (int i = 0; i < 10; i++) {
		if (i + '0' > s[id] && less == 0) {
			break;
		}
		
		add(res, rec(id + 1, (rem + i) % d, less || i + '0' < s[id]));
	}
	
	return dp[id][rem][less] = res;
}
int main() {
	scanf("%s", s);
	scanf("%d", &d);
	
	n = strlen(s);
	
	memset(dp, -1, sizeof(dp));
	
	printf("%d\n", (rec(0, 0, 0) - 1 + MOD) % MOD);
}
