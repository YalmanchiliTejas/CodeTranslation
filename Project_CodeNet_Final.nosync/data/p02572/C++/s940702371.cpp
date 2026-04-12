#include <iostream>
#include <string>

using namespace std;

int main(){
	long long k = 1000000007;
	long long N;
	long long A[200001] = {0};
	long long sum = 0;
	long long s_tmp;
	long long tmp_sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < N; i++) {
		tmp_sum += A[i];
	}
		// cout << "sum = " << sum << "\n";

	for (int i = 0; i < N-1; i++) {
		s_tmp = (A[i] * (tmp_sum%k));
		s_tmp = s_tmp % k;
		sum += s_tmp;
		sum = sum % k;
		tmp_sum -=A[i+1];
		// cout << "sum = " << sum << "\n";
		// cout << "tmp = " << tmp_sum << "\n";
	}
	cout << sum%k << "\n";
	return 0;
}