#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	long long sumA = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		sumA = (sumA + A[i]) % MOD;
	}
	sumA -= A[0];
	if (sumA < 0) sumA += MOD;

	long long ans = 0;
	for (int i = 0; i < N - 1; ++i) {
		ans = (ans + sumA * A[i] % MOD) % MOD;
		sumA -= A[i + 1];
		if (sumA < 0) sumA += MOD;
	}

	cout << ans << endl;
	return 0;
}