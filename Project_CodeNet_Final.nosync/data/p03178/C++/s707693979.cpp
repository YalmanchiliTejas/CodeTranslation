#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;
const int maxd = 110;
const int mod = 1e9 + 7;

string k;
int d;
int dp[maxn][maxd][5];

int rek(int pos, int mod, bool prat) {
	//printf("%d %d %d\n", pos, mod, prat);
	if (pos == k.size()) {
		//printf("GOOD\n");
		if (mod == 0) return 1;
		return 0;
	}
	int &ret = dp[pos][mod][prat];
	if (ret != -1) return ret;
	
	ret = 0;
	if (prat) {
		for (int i = 0; i < 10; i++) {
			//printf("debug: %d\n", i);
			if (i + '0' == k[pos]) {
				ret += rek(pos + 1, (mod + i) % d, true), ret %= ::mod;
				break;
			}
			else ret += rek(pos + 1, (mod + i) % d, false);
			ret %= ::mod;
		} 
	} else {
		for (int i = 0; i < 10; i++) {
			//printf("debug: %d\n", i);
			ret += rek(pos + 1, (mod + i) % d, false), ret %= ::mod;
			//printf("debug end: %d\n", i);
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> k >> d;
	cout << (rek(0, 0, true) + mod - 1) % mod << endl;
	return 0;
}
