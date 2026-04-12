#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N;
	long long X, M;
	cin >> N >> X >> M;
	vector<long long> A, C(M, -1);
	A.push_back(X);
	C[X] = 0;
	long long ans = X;
	long long a = X;
	for (long long i = 1; i < N; i++) {
		a = a * a % M;
		ans += a;
		if (C[a] >= 0) {
			long long loop = 0;
			long long length = A.size() - C[a];
			for (long long j = C[a]; j < A.size(); j++) loop += A[j];
			ans -= a;
			ans += loop * ((N - i) / length);
			i += length * ((N - i) / length);
			for (long long j = 0; i + j < N; j++) ans += A[C[a] + j];
			i = N;
		}
		else {
			C[a] = i;
			A.push_back(a);
		}
	}
	cout << ans << endl;
}
