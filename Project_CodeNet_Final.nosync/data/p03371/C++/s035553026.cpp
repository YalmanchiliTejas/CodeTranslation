#include <iostream>

using namespace std;

int main()
{
	int A, B, C, X, Y;
	int sum;

	cin >> A >> B >> C >> X >> Y;

	if (2*C<A+B) {
		if (X > Y) {
			if (A >= 2 * C ) {
				sum = 2 * C * Y + 2*C*(X - Y);

			}
			else{
				sum = 2 * C * Y + A*(X - Y);
			}
		}
		else{
			if (B >= 2 * C) {
				sum = 2 * C*X + 2 * C*(Y - X);
			}
			else {
				sum = 2 * C*X + B*(Y - X);
			}
		}
	}
	else {
		sum = A*X + B*Y;
	}

	cout << sum << endl;

	return 0;
}