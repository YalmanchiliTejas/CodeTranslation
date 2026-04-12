#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, H;
	cin >> N;
	int total = 1;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> H;
		vec.at(i) = H;
	}
	for (int j = 1; j < N; j++) {
		for (int k = 0; k < j; k++) {
			if (vec.at(k) <= vec.at(j) && k == j - 1) {
				total++;
			}
			else if (vec.at(k) <= vec.at(j) && k < j - 1) {
				continue;
			}
			else {
				break;
			}
		}
	}
	cout << total << endl;
}