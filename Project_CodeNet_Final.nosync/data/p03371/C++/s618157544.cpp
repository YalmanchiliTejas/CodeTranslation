#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, X, Y;
int main() {
	int amount = 0, amount1 = 0, amount2 = 0, amount3 = 0, amount4 = 0;
	cin >> A >> B >> C >> X >> Y;


		amount1 += A*X + B*Y;
	
		amount2 += C*(2*Y);
		if (X > Y) {
			amount2 += A*(X - Y);
		}
		amount = min(amount1, amount2);

		amount3 += C*(2*X);
		if (Y > X) {
			amount3 += B*(Y - X);
		}
		amount = min(amount, amount3);

		if (X < Y) {
			amount4 += C*2*Y;
		}
		else {
			amount4 += C*2*X;
		}
		amount = min(amount, amount4);

	cout << amount << endl;
	return 0;
}