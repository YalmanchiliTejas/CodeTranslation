#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	unsigned int A, B, C, X, Y, min_num, dif, sum;
	cin >> A >> B >> C >> X >> Y;

	min_num = X > Y ? Y : X;
	dif = A + B > 2*C ? 2*C : A + B;
	sum = min_num * dif;

	if (X > Y){
		if (A < 2*C)
			sum += (X - Y) * A;
		else
			sum += (X - Y) * 2*C;
	}
	else if(X < Y){
		if(B < 2*C)
			sum += (Y - X) * B;
		else
			sum += (Y - X) * 2*C;

	}

	cout << sum;

	return 0;
}