#include <iostream>
#include <algorithm>
#define NMAX (200000)
using namespace std;

int main(void) {
	
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int sum;
	
	if(A+B <= 2*C) {
		sum = A*X+B*Y;
	} else {
		if(X<Y)
			if(B > 2*C)
				sum = Y * 2 * C;
			else
				sum = X * 2 * C + (Y - X) * B;
		else
			if(A > 2*C)
				sum = X * 2 * C;
			else
				sum = Y * 2 * C + (X - Y) * A;
	
	}
	cout << sum << endl;
	

	return 0;
}