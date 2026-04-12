#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> d(N);
	for (int& i : d) {
		cin >> i;
		i /= 10;
	}
	int a = d.front(), i;
	for (i = 1; i < N; ++i) {
		if (0 == a) break;
		a = max(a - 1, d[i]);
	}
	if (N == i) {
		a = d.back();
		for (i = N - 2; i >= 0; --i) {
			if (0 == a) break;
			a = max(a - 1, d[i]);
		}
		if (-1 == i) cout << "yes";
		else cout << "no";
	}
	else cout << "no";
	cout << endl;
}
