#include <iostream>

using namespace std;
int main() {
	long int N = 0;
	long int ans;
	cin >> N;
	long int A[N];
	for (long int i = 0; i < N; i++) {
		cin >> A[i];
	}
	long long int c = 0;
	for (long int i = N - 1; i > 0; i--) { //iは配列の番号
		c = (c + A[i]) % 1000000007;
		ans += (c * A[i - 1]) % 1000000007;
	}
	cout << (ans % 1000000007) << endl;
}
