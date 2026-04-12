#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
long long int A[200005];
long long int MOD = 1000000007;



int main(void) {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	long long int sum = 0;

	long long int ans = 0;

	for (int i = 1; i <= N; i++) {
		ans += sum*A[i]; ans %= MOD;
		sum += A[i]; sum %= MOD;
	}

	cout << ans << endl;


	return 0;
}