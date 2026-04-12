#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, X, Y;
int main() {
	cin >> A >> B >> C >> X >> Y;
	cout << min({ A * X + B * Y, 2 * C * (X < Y ? X : Y) + (X > Y ? A * (X - Y) : B * (Y - X)), 2 * C * (X > Y ? X : Y) }) << "\n";
	return 0;
}