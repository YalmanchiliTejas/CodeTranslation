#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if (X < Y) {
		swap(A, B);
		swap(X, Y);
	}
	cout << min({ A*X + B*Y, 2*C*X ,2*C*Y + A*(X - Y) }) << endl;
	return 0;
}