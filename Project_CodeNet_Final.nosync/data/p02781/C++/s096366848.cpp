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

int main() {
	pow9[0] = 1;
	for (int i = 1; i < 4; i++) {
		pow9[i] = pow9[i - 1] * 9;
	}
	string N;
	int K;
	cin >> N >> K;
	long long res = 0;
	for (int index = 0; K <= N.size() - index && index <= N.size(); index++) {
		if (index == N.size()) {
			if (K == 0) res++;
			break;
		}
		if (N[index] == '0') continue;
		int remain = N.size() - index - 1;
		if (remain >= K) {
			res += NchooseK(remain, K) * pow9[K];
		}
		if (remain >= K - 1) {
			int size = N[index] - '0' - 1;
			res += NchooseK(remain, K - 1) * pow9[K - 1] * size;
		}
		K--;
	}
	cout << res << endl;
}
