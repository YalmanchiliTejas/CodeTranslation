#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long N, X, M;
	cin >> N >> X >> M;

	long long sum = 0;
	long long cnt = 0;

	vector<long long> v(M + 1, 0);
	vector<long long> c(M + 1, 0);

	bool jdg = false;
	long long A1, A2;
	A1 = X;

	for (long long i = 1; i <= N; i++) {
		sum += A1;
		cnt += 1;
		if (v[A1] == 0) {
			v[A1] = sum;
			c[A1] = cnt;
		}
		else {
			jdg = true;
			break;
		}
		A2 = A1 % M;
		A2 = A2 * A2;
		A1 = A2 % M;
		if (A1 == 0) {
			break;
		}
	}

	if (jdg == true) {
		long long val = sum - v[A1];
		long long dal = cnt - c[A1];

		long long b = (N - cnt) / dal;
		long long bb = (N - cnt) % dal;

		sum += b * val;

		A2 = A1 % M;
		A2 = A2 * A2;
		A1 = A2 % M;

		for (long long i = 1; i <= bb; i++) {
			sum += A1;
			cnt += 1;
			A2 = A1 % M;
			A2 = A2 * A2;
			A1 = A2 % M;
		}
	}
	
	cout << sum << endl;

	return 0;
}