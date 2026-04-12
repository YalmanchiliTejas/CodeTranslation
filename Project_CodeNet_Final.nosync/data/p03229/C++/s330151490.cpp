#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N;
	cin >> N;

	vector<int64_t> v(N), vec(N);
	for (int i = 0; i < N; i++) cin >> v.at(i);
	sort(v.begin(), v.end());
	
	vector<int64_t> A(N/2), B(N/2);
	int64_t mid = 0;

	if (N % 2 == 0) {
		int64_t c = 0;
		for (int i = 0; i < N / 2; i++) A.at(i) = v.at(i);
		for (int i = N / 2; i < N; i++) {
			B.at(c++) = v.at(i);
		}

		int64_t a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			if (i%2) vec.at(i) = A.at(a++);
			else vec.at(i) = B.at(b++);
		}
		/*for (int i = 0; i < A.size(); i++) cout << A.at(i);
		cout << endl;
		for (int i = 0; i < B.size(); i++) cout << B.at(i);
		cout << endl;*/
		/*for (int i = 0; i < N; i++) cout << vec.at(i);
		cout << endl;*/

		int64_t d = 0;
		for (int i = 1; i < N; i++) {
			d += abs(vec.at(i) - vec.at(i - 1));
		}
		cout << d << endl;
	}
	else {
		vector<int64_t> vec(N-1);

		int64_t c = 0;
		for (int i = 0; i < N / 2; i++) A.at(i) = v.at(i);
		for (int i = N / 2 + 1; i < N; i++) {
			B.at(c++) = v.at(i);
		}
		mid = v.at(N / 2);
		//cout << mid << endl;

		int64_t a = 0, b = 0;
		for (int i = 0; i < N - 1; i++) {
			if (i % 2) vec.at(i) = A.at(a++);
			else vec.at(i) = B.at(b++);
			//cout << vec.at(i);
		}
		//cout << endl;

		//cout << vec.size() << endl;
		vector<int64_t> vec2 = { mid };
		for (int i = 0; i < N-1;i++) {
			vec2.push_back(vec.at(i));
		}
		vec.push_back(mid);

		//for (int i = 0; i < N; i++) cout << vec.at(i);
		//cout << endl;
		//for (int i = 0; i < N; i++) cout << vec2.at(i);
		//cout << endl;

		int64_t d1 = 0, d2 = 0;
		for (int i = 1; i < N; i++) {
			d1 += abs(vec.at(i) - vec.at(i - 1));
		}
		for (int i = 1; i < N; i++) {
			d2 += abs(vec2.at(i) - vec2.at(i - 1));
		}

		cout << max(d1,d2) << endl;
	}

}