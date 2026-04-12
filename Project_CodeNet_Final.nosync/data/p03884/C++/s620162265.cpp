#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000, M = 600;
ll dp[N][26], n, ans[M + 1];
string s, p = "FESTIVA";


ll calc(int i, int j) {
	if (j == 'A')
		return 1;
	if (i == n)
		return 0;
	ll &ret = dp[i][j];
	if (ret != -1)
		return ret;
	ret = calc(i + 1, j);
	if (p[p.find(j) + 1] == s[i])
		ret += calc(i + 1, s[i]);
	return ret;
}
int main(int argc, char **argv) {
	for (int i = 1; i <= M; ++i) {
		s += p;
		memset(dp, -1, sizeof dp);
		n = s.size();
		ans[i] = calc(0, 'Q');
	}
	reverse(p.begin(), p.end());
	s.clear();
	ll x, t;
	cin >> x;
	for (int i = 600; i >= 1; --i) {
		t = x / ans[i];
		s += string(t, 'L') + p;
		x -= t * ans[i];
	}
	reverse(s.begin(), s.end());
	puts(s.c_str());
	return 0;
}
