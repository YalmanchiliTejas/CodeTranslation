#include <iostream>
#define MAX_INT 2147483647
using namespace std;
int Max(int a, int b) {	return a > b ? a : b;};

int main() {

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int cost = MAX_INT;

	for (int i = 0; i <= X + Y; i++) {
		int cost_tmp = 2*C*i + A*Max(0, X - i) + B*Max(0, Y - i);
		cost = (cost_tmp < cost) ? cost_tmp : cost;
	}
	cout << cost << endl;

	return 0;
}