#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) cin >> x;
	auto B = A;
	sort(B.begin(), B.end());
	for (auto x : A) {
		if (x <= B[N/2-1]) {
			cout << B[N/2] << endl;
		} else {
			cout << B[N/2-1] << endl;
		}
	}
}
