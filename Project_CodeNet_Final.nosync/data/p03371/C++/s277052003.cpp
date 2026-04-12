#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int A, B, AB; // ピザの値段
int X, Y; // 必要枚数

int main() {
	int cost = 0; // 総費用
	cin >> A >> B >> AB >> X >> Y;

	if ((A + B) > AB * 2) {
		int less = min(X, Y); // 少ないほう
		cost += AB * less * 2;
		if (less == X) {
			if (B / 2 > AB) {
				cost += AB * (Y - less) * 2;
			}
			else {
				cost += B * (Y - less);
			}
		}
		else {
			if (A / 2 > AB) {
				cost += AB * (X - less) * 2;
			}
			else {
				cost += A * (X - less);
			}
		}
	}
	else {
		cost += A * X;
		cost += B * Y;
	}

	cout << cost << endl;

	return 0;
}