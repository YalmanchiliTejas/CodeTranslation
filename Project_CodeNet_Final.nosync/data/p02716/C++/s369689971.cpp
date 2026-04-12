#pragma warning( disable : 6031)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <math.h>
int minimum(int a, int b) { return a < b ? a : b; }
int maximum(int a, int b) { return a > b ? a : b; }
const long long mod = 1000000007;
//const long long mod = 998244353;
using std::vector;
using std::pair;
using std::string;
using std::map;
using std::priority_queue;
int main() {
	int N;
	scanf("%d", &N);
	auto A = new int[N];
	for (int i = 0; i < N; i++)scanf("%d", A + i);
	long long oddsum = 0, evemsum = 0;
	auto oddsums = new long long[N / 2]{};
	auto evensums = new long long[(N + 1) / 2]{};
	long long max = -mod * N;
	for (int i = 0; i < N; i++) {
		if (i & 1) {
			oddsum += A[i];
			oddsums[i / 2] = oddsum;
		}
		else {
			evemsum += A[i];
			evensums[i / 2] = evemsum;
		}
	}
	if (N & 1) {
		max = oddsum;
		auto maxs = new long long[N / 2 + 1]{};
		maxs[0] = max;
		for (int i = 0; i < N / 2; i++) {
			long long sum = evensums[i] + oddsum - oddsums[i];
			max = sum < max ? max : sum;
			maxs[i + 1] = max;
		}
		long long d = 0;
		for (int i = N / 2; i >= 1; i--) {
			d += A[i * 2] - A[i * 2 - 1];
			long long sum = maxs[i - 1] + d;
			max = sum < max ? max : sum;
		}
	}
	else {
		max = oddsum;
		for (int i = 0; i < N / 2; i++) {
			long long sum = evensums[i] + oddsum - oddsums[i];
			max = sum < max ? max : sum;
		}
	}
	printf("%lld", max);
	return 0;
}