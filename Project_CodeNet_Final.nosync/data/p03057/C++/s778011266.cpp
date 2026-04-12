#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

// 入力
long long mod = 1000000007;
long long N, M;
string S;

// その他
long long fib[1 << 19];
long long dp[1 << 19], ru[1 << 19];
long long ret[1 << 19];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long p, long long q, long long m) {
	return (p * modpow(q, m - 2, m)) % m;
}

long long solve(long long n, long long r) {
	for (int i = 0; i <= N; i++) dp[i] = 0;
	for (int i = 0; i <= N; i++) ru[i] = 0;
	for (int i = 1; i <= r / 2; i++) dp[i] = 1LL * (i * 2);
	for (int i = 1; i <= n / 2; i++) {
		long long v = ru[i - 1]; if (i - (r / 2) - 1 >= 0) v -= ru[i - (r / 2) - 1];
		v = (v + mod) % mod;
		dp[i] += v; dp[i] %= mod;
		ru[i] = (dp[i] + ru[i - 1]) % mod;
	}
	
	long long val = dp[n / 2];
	return val;
}

int main() {
	cin >> N >> M >> S;

	// 判定
	bool flag = false;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] != S[i + 1]) flag = true;
	}

	// 特殊
	if (flag == false) {
		fib[0] = 1;
		fib[1] = 1;
		for (int i = 2; i <= N; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
		cout << (fib[N] + fib[N - 2]) % mod << endl;
		return 0;
	}

	// 奇数
	if (N % 2 == 1) {
		cout << "0" << endl;
		return 0;
	}

	// 偶数
	if (S[0] == 'B') {
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'B') S[i] = 'R';
			else S[i] = 'B';
		}
	}
	int MaxLength = N, cur = 0, cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'R') cur++;
		else {
			if (cnt == 0) {
				MaxLength = min(MaxLength, cur);
			}
			else if (cur % 2 == 1) {
				MaxLength = min(MaxLength, cur);
			}
			cur = 0; cnt++;
		}
	}
	MaxLength += 2;

	vector<long long> E;
	for (int i = 1; i <= N / 2; i++) {
		if ((N / 2) % i == 0) E.push_back(i);
	}
	for (int i = E.size() - 1; i >= 0; i--) {
		long long d1 = (N / E[i]);
		long long d2 = MaxLength;
		ret[i] = solve(d1, d2);
		for (int j = i + 1; j < E.size(); j++) {
			if (E[j] % E[i] == 0) { ret[i] -= ret[j]; ret[i] = (ret[i] + mod) % mod; }
		}
	}

	long long FinalAns = 0;
	for (int i = 0; i < E.size(); i++) {
		FinalAns += 1LL * ret[i];
		FinalAns %= mod;
	}
	cout << FinalAns << endl;
	return 0;
}