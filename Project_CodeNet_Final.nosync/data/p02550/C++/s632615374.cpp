
#include <bits/stdc++.h>
//#include <atcoder/all>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 998244353; //1000000007

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void E();

int main()
{
	E();
	fflush(stdout);
	return 0;
}

static void E()
{
	LLONG N, X, M;
	get(N, X, M);

	std::set<LLONG> nums;
	std::vector<LLONG> ai(1);
	ai[0] = X;
	LLONG sum = X, looped = 0;
	nums.insert(X);
	bool zero = false;
	for (LLONG i = 1; i <= N; i++) {
		LLONG num = (ai[i - 1] * ai[i - 1]) % M;
		if (num == 0) {
			zero = true;
			break;
		}
		if (nums.find(num) == nums.end()) {
			sum += num;
			nums.insert(num);
			ai.push_back(num);
		}
		else {
			looped = num;
			break;
		}
	}

	LLONG ans = 0;
	if (zero) {
		for (int i = 0; i < N && i < ai.size(); i++) {
			ans += ai[i];
		}
	}
	else {
		int loopIdx = 0;
		while (looped != ai[loopIdx]) loopIdx++;
		
		if (N <= (LLONG)ai.size()) {
			for (int i = 0; i < N; i++) {
				ans += ai[i];
			}
		}
		else {
			ans = sum;

			LLONG count = N - (LLONG)ai.size();
			LLONG mul = count / (LLONG)(ai.size() - loopIdx);
			LLONG surp = count % (LLONG)(ai.size() - loopIdx);
			int cnt = ai.size();
			LLONG loopSum = 0;
			for (int i = loopIdx; i < cnt; i++) {
				loopSum += ai[i];
			}
			ans += (loopSum * mul);
			for (int i = 0; i < surp; i++) {
				ans += ai[i + loopIdx];
			}
		}
	}
	printf("%lld\n", ans);
}
