

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

long sum(vector <long> v) {
	long s=0;
	long n = v.size();
	for (long i = 0; i < n; i++) {
		s = s + v[i];
	}
	return s;
}

int main()
{
	string str;
	getline(cin, str);
	int N = stoi(str);

	vector <long> A;

	for (long i = 0; i < N; i++) {
		getline(cin, str);
		A.push_back(stoi(str));
	}
	long ans=0;
	sort(A.begin(), A.end());
	if (N % 2 == 0) {
		vector <long> U, L;
		for (int i = 0; i < N; i++) {
			if (i < N / 2) {
				L.push_back(A[i]);
			}
			else {
				U.push_back(A[i]);
			}
		}
		ans = (sum(U) * 2 - U[0]) - (sum(L) * 2 - L[N/2-1]);
	}
	else if (N == 3) {
		long ans1, ans2;
		ans1 = A[2]  + A[1] - A[0] * 2;
		ans2 = A[2] * 2 - A[1] - A[0];
		ans = ans1 > ans2 ? ans1 : ans2;
	}
	else{
		vector <long> U1, L1, U2, L2;
		long ans1, ans2;
		for (int i = 0; i < N; i++) {
			if (i < (N-1) / 2) {
				L1.push_back(A[i]);
			}
			else {
				U1.push_back(A[i]);
			}
		}
		for (int i = 0; i < N; i++) {
			if (i < (N - 1) / 2 + 1) {
				L2.push_back(A[i]);
			}
			else {
				U2.push_back(A[i]);
			}
		}
		ans1 = (sum(U1) * 2 - U1[0] - U1[1]) - (sum(L1) * 2);
		ans2 = (sum(U2) * 2) - (sum(L2) * 2 - L2[(N-1)/2] - L2[(N - 1) / 2 -1]);
		ans = ans1 > ans2 ? ans1 : ans2;
	}

	cout << ans << endl;

	return 0;
}
