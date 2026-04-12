#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }
ll MOD = 1000000007;


int main() {
	int N;
	cin >> N;
	vector<ll> A(N + 1), B(N);
	A[0] = 0;
	for (int i = 1; i <= N; i++ ) cin >> A[i];
	B[N - 1] = A[N];
	for (int i = N - 1; i >= 2; i--) {
		B[i - 1] = (B[i] + A[i]) % MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= N - 1; i++) {
		ans = (ans +  (A[i] * B[i])%MOD)%MOD;
	}
	cout << ans << endl;
}