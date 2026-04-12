#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a; char b;
	for (int h = 0; h < 100; h++) {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			cin >> n >> a;
			if (n == 0 && a == 0) {
				cin >> n; return 0;
			}
			if (n + a > sum) {
				sum = n + a;
				if (i == 0) { b = 'A'; }
				if (i == 1) { b = 'B'; }
				if (i == 2) { b = 'C'; }
				if (i == 3) { b = 'D'; }
				if (i == 4) { b = 'E'; }
			}
		}
		cout << b << ' ' << sum << endl;
	}
	cin >> n;
}
