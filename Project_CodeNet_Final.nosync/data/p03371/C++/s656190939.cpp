#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int A, B, C, X, Y;
	int sum;
	cin >> A >> B >> C >> X >> Y;
	if (A + B < C * 2) {
		sum = A*X + B*Y;
	}
	else {
		if (X < Y) {
			if (B < 2 * C) {
				sum = 2 * C*X + B*(Y - X);
			}
			else {
				sum = 2 * C*Y;
			}
		}
		else {
			if (A < 2 * C) {
				sum = 2 * C*Y + A*(X - Y);
			}
			else {
				sum = 2 * C*X;
			}
		}
	}
	cout << sum << endl;
	return 0;
}