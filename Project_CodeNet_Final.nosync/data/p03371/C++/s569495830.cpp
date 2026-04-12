#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int common=min(X, Y);
	int S=common*min(A+B, 2*C);
	X -= common; Y -= common;
	S += X*min(A, 2*C) + Y*min(B, 2*C);
	cout << S << endl;
	return 0;
}
