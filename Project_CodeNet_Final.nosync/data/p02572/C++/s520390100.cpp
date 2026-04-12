#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007, Answer;
long long N, A[1 << 18], B[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) B[i] = (B[i - 1] + A[i]) % mod;
	for (int i = 1; i <= N; i++) Answer += (A[i] * B[i - 1]) % mod;
	cout << Answer % mod << endl;
	return 0;
}