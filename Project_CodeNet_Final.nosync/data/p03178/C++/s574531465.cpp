#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
using LL = long long;
#define REP(i, n) for(int i = 0; i < (n); ++i)

constexpr int mod = int(1e9) + 7;

int add(int a, int b, int m) {
	a += b;
	return a >= m ? a - m : a;
}
int& add_to(int &a, int b, int m) {
	a += b;
	if(a >= m)
		a -= m;
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string k;
	int d;
	cin >> k >> d;

	vector<int> dp(d), prev_dp(d);
	int curr_sum = 0;
	REP(i, int(k.size())) {
		fill(dp.begin(), dp.end(), 0);
		REP(sum, d)
			REP(last, 10)
				add_to(dp[add(sum, last % d, d)], prev_dp[sum], mod);
		int digit = int(k[i] - '0');
		REP(c, digit)
			add_to(dp[add(curr_sum, c % d, d)], 1, mod);
		add_to(curr_sum, digit % d, d);
		prev_dp = dp;
	}
	cout << add(dp[0], mod - 1 + (curr_sum % d == 0), mod) << '\n';
}
