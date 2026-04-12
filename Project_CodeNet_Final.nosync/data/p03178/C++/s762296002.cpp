#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<map>
#include<bitset>
#include<utility>
//#include<unordered_map>
#ifdef LOCAL
#include"file.h"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const double eps = 1e-12;
const double Pi = 3.1415926535897932;
const int dir[4][2] = { -1,0,1,0,0,-1,0,1 };
//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };






const int maxn = 10000 + 5;
const int MOD = 1e9 + 7;


int f[maxn][100 + 5];

char s[maxn];
int n, D;
int main() {
#ifdef LOCAL
	fileopen();
#endif
	scanf("%s", s + 1);
	scanf("%d", &D);
	n = strlen(s + 1);

	

	f[n+1][0] = 1;
	for (int i = n+1; i >= 2; i--) {
		for (int j = 0; j < D; j++)if(f[i][j]) {
			for (int k = 0; k <= 9; k++) {
				f[i - 1][(j + k) % D] += f[i][j];
				f[i - 1][(j + k) % D] %= MOD;
			}
		}
	}

	int ans = MOD - 1;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < s[i] - '0'; j++) {
			ans += f[i + 1][(t - j % D + D) % D];
			ans %= MOD;
		}
		t = (t - (s[i] - '0')%D + D) % D;
	}
	//ans = (ans - 1 + MOD) % MOD;

	t = 0;
	for (int i = 1; i <= n; i++)
		t = (t + s[i] - '0') % D;
	if (!t)ans = (ans + 1) % MOD;

	printf("%d\n", ans);



#ifdef LOCAL
	fileclose();
#endif
	return 0;
}
