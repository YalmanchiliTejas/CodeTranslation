#include <iostream>
#include <string>
using namespace std;

long long pow9[4];

inline long long NchooseK(int N, int K) {
	long long res = 1;
	for (int i = 1; i <= K; i++, N--) {
		res = res * N / i;
	}
	return res;
}

long long dfs(const string& N, int index, int K, bool bounded) {
	if (K < 0) return 0;
	if (index == N.size()) {
		return K == 0;
	}
	int remain = N.size() - index;
	if (remain < K) return 0;
	if (!bounded) {
		return NchooseK(remain, K) * pow9[K];
	}
	long long res = 0;
	for (int i = 0; i <= N[index] - '0'; i++) {
		res += dfs(N, index + 1, K - (i != 0), i == N[index] - '0');
	}
	return res;
}

int main() {
	pow9[0] = 1;
	for (int i = 1; i < 4; i++) {
		pow9[i] = pow9[i - 1] * 9;
	}
	string N;
	int K;
	cin >> N >> K;
	cout << dfs(N, 0, K, true) << endl;
}