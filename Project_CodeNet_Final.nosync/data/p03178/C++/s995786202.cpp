#include <bits/stdc++.h>
#define int long long
#define N 10011

using namespace std;

const int MOD = (int)1e9 + 7;

int n, d;
int p[N], cnt[N][2][100];
string k;

int solve(int idx, int ok, int mod) {
	if(idx == n) return mod == 0;
	if(cnt[idx][ok][mod] != -1) return cnt[idx][ok][mod];
	int res = 0;
	if(ok) {
		for(int i=0; i<10; i++) {
			res = (res + solve(idx+1, ok, (mod + i) % d)) % MOD;
		}
	}
	else {
		res = solve(idx+1, 0, (mod + (k[idx] - '0')) % d);
		for(int i=0; i<k[idx]-'0'; i++) res = (res + solve(idx+1, 1, (mod + i) % d)) % MOD;
	}
	return cnt[idx][ok][mod] = res;
}

signed main() {
	memset(cnt, -1, sizeof cnt);
	cin >> k >> d;
	n = k.size();
	cout << (solve(0,0,0) + MOD - 1) % MOD << endl;
	return 0;
}
