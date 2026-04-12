#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	long long sum1 = 0, sum2 = 0;
	for (int i = N - 1; i > 0; i--) {
		sum1 = (sum1 + A[i]) % 1000000007;
		sum2 += ((long long)A[i - 1] * sum1) % 1000000007;
		sum2 %= 1000000007;
	}
	cout << sum2 << endl;
}