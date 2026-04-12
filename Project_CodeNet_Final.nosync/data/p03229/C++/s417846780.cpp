#include<iostream>
#include <complex>
#include <vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<list>
#include <iterator>
#include <utility>
#include <numeric>
using namespace std;

#define intt long long




int main() {
	int N;

	vector<int> A;
	intt x, y;
	cin >> N;
	intt sum = 0;
	A.resize(N);
	int size = 0;
	int	flag=0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());
	int max = N;

	int a, b, c, d;
	for (int i = 0; i != N;i++) {
		if (size < 1) {
			x = A[N -1];
			y = A[N - 1];
			A.erase(A.begin() + A.size() - 1);
			size += 1;
			continue;
		}


		a = abs(x - A[0]);
		b = abs(y - A[0]);
		c = abs(x - A[A.size() - 1]);
		d = abs(y - A[A.size() - 1]);

		if (a >= b && a >= c && a >= d) {
			sum += abs(A[0] - x);
			x = A[0];
			A.erase(A.begin());
		}
		else if (b >= a && b >= c && b >= d) {
			sum += abs(A[0] - y);
			y = A[0];
			A.erase(A.begin());
		}
		else if (c >= a&& c >= b&& c >= d) {
			sum += abs(A[A.size() - 1] - x);

			x = A[A.size() - 1];
			A.erase(A.begin() + A.size() - 1);
		}
		else if (d >= a&& d >= b&&d >= c) {
			sum += abs(A[A.size() - 1] - y);

			y = A[A.size() - 1];
			A.erase(A.begin() + A.size() - 1);
		}


	}
	cout << sum << endl;

	return 0;

}