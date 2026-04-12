#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	long long n, m, a = 1, b = 1, e = 0;
	cin >> n;
	int test[200001] = { 0 };
	if (n % 2 == 0) {
		for (int h = 1; h <= n; h++) {
			cin >> m;
			if (h % 2 == 0) {
				test[100001 - h / 2] = m;
			}
			else {
				test[100001 + h / 2] = m;
			}
		}
		for (int i = 100001 - n / 2; i <= 100001 + n / 2 - 1; i++) {
			cout << test[i] << ' ';
		}
	}
	else {
		for (int h = 1; h <= n; h++) {
			cin >> m;
			if (h % 2 == 0) {
				test[100001 + h / 2] = m;
			}
			else {
				test[100001 - h / 2] = m;
			}
		}
		for (int i = 100001 - n / 2; i <= 100001 + n / 2; i++) {
			cout << test[i] << ' ';
		}
	}
	cin >> e;
}