#include<iostream>
#include<vector>
using namespace std;

#define int long long

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

signed main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; i++)cin >> D[i];

	int tmp = 1;
	for (int i = 0; i < N; i++) {
		tmp--;
		if (tmp < 0) {
			cout << "no" << endl;
			return 0;
		}
		tmp = max(D[i] / 10,tmp);
	}
	tmp = 1;
	for (int i = N - 1; i >= 0; i--) {
		tmp--;
		if (tmp < 0) {
			cout << "no" << endl;
			return 0;
		}
		tmp = max(D[i] / 10, tmp);
	}
	cout << "yes" << endl;
	return 0;
}
