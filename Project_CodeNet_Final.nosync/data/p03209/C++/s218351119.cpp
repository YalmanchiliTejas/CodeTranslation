#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int> > nyu(int h, int w) {
	vector<vector<int> > a(h + 2, vector<int>(w + 2, h*w + 1));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i + 1][j + 1];
		}
	}
	return a;
}
vector<int> nyu1(int n) {
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	return c;
}
long long rui(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return 2 * rui(n - 1);
	}
}
long long pad(int n, long long x) {
	if (n == 0) {
		return 1;
	}
	else if (x == 1) {
		return 0;
	}
	else {
		long long a = rui(n+1) - 3;
		if (x <= a + 1) {
			return pad(n - 1, x - 1);
		}
		else if (x == a + 2) {
			return rui(n);
		}
		else if (x == 2*a + 3) {
			return 2 * rui(n) - 1;
		}
		else {
			return rui(n) + pad(n-1, x - a - 2);
		}
	}
}
int main() {
	int n; long long x;
	cin >> n >> x;
	cout << pad(n, x) << endl;
}