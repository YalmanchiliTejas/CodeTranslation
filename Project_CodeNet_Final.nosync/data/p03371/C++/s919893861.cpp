#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int need = A*X+B*Y;

	for (int i = 0; i <= max(X,Y); i++) {
		need = min(need, C * 2 * i + A*max((X - i),0) + B*max(0,(Y - i)));
	}
	cout << need;
	return 0;
}