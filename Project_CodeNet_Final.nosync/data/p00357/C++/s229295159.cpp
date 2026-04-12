#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 99999999
int main() {
	int N;
	cin >> N;
	vector<int> d(N);
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		d[i] /= 10;
	}
	int dmax = d[0];
	bool flag = false;
	for (int i = 1; i <= dmax; i++) {
		if (i + d[i] > dmax) dmax = i + d[i];
		if (dmax >= N - 1) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "no" << endl;
		return 0;
	}

	reverse(d.begin(), d.end());
	dmax = d[0];
	flag = false;
	for (int i = 1; i <= dmax; i++) {
		if (i + d[i] > dmax) dmax = i + d[i];
		if (dmax >= N - 1) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	return 0;
}
