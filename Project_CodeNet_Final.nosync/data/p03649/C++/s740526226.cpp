#include<iostream>

using namespace std;

typedef long long ll;

int N;
ll a[50];
ll K;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> a[i];
	while (true) {
		bool update = false;
		ll total = 0, dec[50] = {};
		for (int i = 0; i < N; i++) {
			total += (a[i] / N);
			dec[i] = (a[i] / N);
			if (a[i] / N != 0)update = true;
		}
		K += total;
		for (int i = 0; i < N; i++) {
			a[i] %= N;
			a[i] += (total - dec[i]);
		}
		if (!update)break;
	}
	cout << K << endl;
	return 0;
}