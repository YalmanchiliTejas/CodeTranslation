#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

static const ULL M = 1000000007;

struct Problem {
public:

	string S;
	UL D;
	ULL dp[100] = {};
	ULL buf[100] = {};
	UL sum = 0;

	void Solve() {
		cin >> S >> D;
		for (char c : S) {
			UL d = c - '0';
			rep(i, D) buf[i] = 0;
			rep(i, D) rep(d, 10) buf[(i + d) % D] += dp[i];
			rep(p, d) buf[(sum + p) % D] += 1;
			rep(i, D) dp[i] = buf[i] % M;
			sum += d;
		}
		dp[0] = (dp[0] + M - 1) % M;
		dp[sum % D] = (dp[sum % D] + 1) % M;
		printf("%llu", dp[0]);
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
