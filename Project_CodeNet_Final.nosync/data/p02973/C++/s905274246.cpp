#include <iostream>
#include <algorithm>
using namespace std;

long long N, S, A[1 << 18], B[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; A[i] *= -1; }
	for (int i = 1; i <= N; i++) {
		int pos1 = lower_bound(B, B + S, A[i] + 1) - B;
		if (pos1 == S) { S++; }
		B[pos1] = A[i];
	}
	cout << S << endl;
	return 0;
}