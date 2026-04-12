#include <bits/stdc++.h>

using namespace std;

const int L = 1e4;
const int D = 1e2;
const int MOD = 1e9+7;

string k;
int l, d;
int total[L][2][D];

int solve(int p, bool state, int re) {
	if(p == l) {
		if(re == 0) return 1;
		return 0;
	}
	
	int &ref = total[p][state][re];
	if(ref != -1) return ref;
	
	int curr = 0, up = (state) ? (k[p]-'0') : 9;
	for(int i = 0; i < up; i++) curr = (curr + solve(p+1, false, (re+i) % d)) % MOD;
	curr = (curr + solve(p+1, state, (re+up) % d)) % MOD;
	
	ref = curr;
	return curr;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(total, -1, sizeof(total));
	
	cin >> k >> d;
	l = k.length();
	cout << ((solve(0, true, 0)-1) + MOD) % MOD;
}