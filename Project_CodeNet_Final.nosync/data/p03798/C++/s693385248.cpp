
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;


const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}


int main() {
	ll i, j, k, l, m, n, sum, flag, cc,N,M,X;
	sum = 0;
	flag = 0;
	cin >> N;
	char s[100001];
	char ans[100001];
	cin >> s;
	char s1[2] = { 'S','W' };
	char s2[2] = { 'o','x' };
	//最初の二つがS,S.
	ans[0] = s1[0];
	ans[1] = s1[0];
	REP(i, 2, N) {
		if ((s[i - 1] == s2[0] && ans[i - 1] == s1[0])||(s[i-1]==s2[1]&&ans[i-1]==s1[1])) {
			ans[i] = ans[i - 2];
		}
		else {
			if (ans[i - 2] == s1[0]) {
				ans[i] = s1[1];
			}
			else {
				ans[i] = s1[0];
			}
		}

	}
	if ((s[N - 1] == s2[0]&&ans[N-1]==s1[0])||(s[N-1]==s2[1]&&ans[N-1]==s1[1])) {
		if (ans[N - 2] == ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					
					}
					return 0;
				}
			}
			
	}
	}
	else {
		if (ans[N - 2] != ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			
		}
	}
	//最初の二つがW,S.
	ans[0] = s1[1];
	ans[1] = s1[0];
	REP(i, 2, N) {
		if ((s[i - 1] == s2[0] && ans[i - 1] == s1[0]) || (s[i - 1] == s2[1] && ans[i - 1] == s1[1])) {
			ans[i] = ans[i - 2];
		}
		else {
			if (ans[i - 2] == s1[0]) {
				ans[i] = s1[1];
			}
			else {
				ans[i] = s1[0];
			}
		}

	}
	if ((s[N - 1] == s2[0] && ans[N - 1] == s1[0]) || (s[N - 1] == s2[1] && ans[N - 1] == s1[1])) {
		if (ans[N - 2] == ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			
		}
	}
	else {
		if (ans[N - 2] != ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			
		}
	}
	//最初の二つがS,W.
	ans[0] = s1[0];
	ans[1] = s1[1];
	REP(i, 2, N) {
		if ((s[i - 1] == s2[0] && ans[i - 1] == s1[0]) || (s[i - 1] == s2[1] && ans[i - 1] == s1[1])) {
			ans[i] = ans[i - 2];
		}
		else {
			if (ans[i - 2] == s1[0]) {
				ans[i] = s1[1];
			}
			else {
				ans[i] = s1[0];
			}
		}

	}
	if ((s[N - 1] == s2[0] && ans[N - 1] == s1[0]) || (s[N - 1] == s2[1] && ans[N - 1] == s1[1])) {
		if (ans[N - 2] == ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}

		}
	}
	else {
		if (ans[N - 2] != ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			
		}
	}
	//最初の二つがW,W.
	ans[0] = s1[1];
	ans[1] = s1[1];
	REP(i, 2, N) {
		if ((s[i - 1] == s2[0] && ans[i - 1] == s1[0]) || (s[i - 1] == s2[1] && ans[i - 1] == s1[1])) {
			ans[i] = ans[i - 2];
		}
		else {
			if (ans[i - 2] == s1[0]) {
				ans[i] = s1[1];
			}
			else {
				ans[i] = s1[0];
			}
		}

	}
	if ((s[N - 1] == s2[0] && ans[N - 1] == s1[0]) || (s[N - 1] == s2[1] && ans[N - 1] == s1[1])) {
		if (ans[N - 2] == ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
		
		}
	}
	else {
		if (ans[N - 2] != ans[0]) {
			if ((s[0] == s2[0] && ans[0] == s1[0]) || (s[0] == s2[1] && ans[0] == s1[1])) {
				if (ans[N - 1] == ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			else {
				if (ans[N - 1] != ans[1]) {
					REP(i, 0, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
			
		}
	}

	output("-1");


	return 0;
}