#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <map>

const int mod = 1000000007;
//const int mod = 998244353;
int maximum(int a, int b) { return a < b ? b : a; }

long long K3(char* S, int N, int n0) {
	long long res = 0;
	int s = 0;
	for (int i = 0; i < maximum(n0, 3); i++) {
		while (1) {
			if (S[s] == 0)break;
			if (S[s] != '0') {
				int a = S[s] - '0';
				int m = N - s;
				switch (i) {
				case 0:
					res += 9LL * 9 * 9 * (N - 1)*(N - 2)*(N - 3) / 6;
					res += (a - 1) * 9LL * 9 * (N - 1)*(N - 2) / 2;
					if (n0 == 1) {
						//res += 9LL * 9 * (N - 1)*(N - 2) / 2;
					}
					break;
				case 1:
					res += 9 * 9 * (m - 1)*(m - 2) / 2;
					res += (a - 1) * 9 * (m - 1);
					if (n0 == 2) {
						//res += 9 * (m - 1);
					}
					break;
				case 2:
					int k = N - s;
					res += 9 * (k - 1);
					res += a;
					break;
				}
				s++;
				break;
			}
			s++;
		}
	}
	return res;
}

long long K2(char*S, int N, int n0) {
	long long res = 0;
	int s = 0;
	for (int i = 0; i < maximum(n0, 2); i++) {
		while (1) {
			if (S[s] == 0)break;
			if (S[s] != '0') {
				int a = S[s] - '0';
				int m = N - s;
				switch (i) {
				case 0:
					res += 9LL * 9 * (N - 1)*(N - 2) / 2;
					res += (a - 1) * 9LL * (N - 1);
					if (n0 == 1) {
						//res += 9LL * (N - 1);
					}
					break;
				case 1:
					res += 9 * (m - 1);
					res += a;
					break;
				}
				s++;
				break;
			}
			s++;
		}
	}
	return res;
}
int K1(char*S, int N, int n0) {
	int res = 9 * (N - 1);
	res += S[0] - '0';
	return res;
}
int main() {
	char S[101];
	scanf("%s", S);
	int K;
	scanf("%d", &K);
	int n0 = 0;
	int N = 0;
	for (; S[N] != 0; N++) {
		if (S[N] != '0') {
			n0++;
		}
	}
	long long res;
	switch (K)
	{
	case 1:
		res = K1(S, N, n0);
		break;
	case 2:
		res = K2(S, N, n0);
		break;
	case 3:
		res = K3(S, N, n0);
		break;
	}
	printf("%lld", res);
	return 0;
}