#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<numeric>

typedef long long LL;

using namespace std;

LL gcd(LL a, LL b) {
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b) * b);
}


int main(void) {
	int h, w;
	cin >> h >> w;
	vector<string>a(h);
	for (int i = 0; i < h; i++)cin >> a[i];
	vector<bool>hf(w, false), wf(h, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				hf[j] = true;
				wf[i] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (wf[i]) {
			for (int j = 0; j < w; j++) {
				if (hf[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}