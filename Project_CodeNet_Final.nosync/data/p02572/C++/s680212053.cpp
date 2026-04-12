#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <deque>
#include <set>
using namespace std;
#define MOD 1000000007
#define MOD2 2000000014
#define LONG long long
long long kaizyo(int N);
long long P(int N, int M);
long long pow(int a, int n) {
	long long result = 1;
	for (int i = 0; i < n; i++) {
		result *= a;
		result = result % MOD;
	}
	return result;
}
int main()
{
	int N;
	cin >> N;

	vector<LONG>A(N);
	LONG sum = 0;
	LONG sum2 = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		sum2 += ((A[i] * A[i])) % MOD2;
	}
	sum = sum % MOD2;
	sum = (sum * sum)%MOD2;
	sum2 = sum2 % MOD2;
	if (sum < sum2) {
		sum += MOD2;
	}



	LONG result = ((sum - sum2)/2);
	cout << result % MOD;
	return 0;
}
long long kaizyo(int N) {
	long long result = 1;
	for (int i = 2; i <= N; i++) {
		result *= i;
		result = result % MOD;
	}
	return result;
}
long long P(int N, int M) {
	long long result = 1;
	for (int i = (N - M + 1); i <= N; i++) {
		result *= i;
		result = result % MOD;
	}
	return result;
}
