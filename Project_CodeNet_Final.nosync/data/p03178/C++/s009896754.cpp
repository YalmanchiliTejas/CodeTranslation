#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0;i<n;i++)
#define reps(i,s,n) for(long long i=s;i<n;i++)
using namespace std;
const long long mod = (long long)(1E9) + 7LL;
long long dgtdp(int k, bool t, int md, int& d, string& s, vector<vector<vector<long long>>>& memo) {
	if (memo[k][t][md] != -1) return memo[k][t][md];
	if (k == s.size()) return md == 0;
	int x = s[k] - '0';
	int lim = (t) ? x : 9;
	long long ret = 0;
	for (int i = 0; i <= lim; i++) {
		ret += dgtdp(k + 1, t and (i == lim), (md + i) % d, d, s, memo);
		ret %= mod;
		memo[k][t][md] = ret;
	}
	return ret;
}

int main(void) {
	string s;
	int d;
	cin >> s >> d;
	vector<vector<vector<long long>>> memo(s.size() + 1, vector<vector<long long>>(2, vector<long long>(d, -1LL)));
	cout << (dgtdp(0, true, 0, d, s, memo)+mod - 1)%mod << endl;
}