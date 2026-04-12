#include <iostream>

using namespace std;

int N;
long long int X;

long long int a[55], c[55];

long long int CALL(int N, long long int X) {

	if (X == a[N]) { return c[N - 1] * 2 + 1; }
	else if (X > (a[N] + 1) / 2) { return c[N - 1] + 1 + CALL(N - 1, X - (a[N] + 1) / 2); }
	else if (X == (a[N] + 1) / 2) { return c[N - 1] + 1; }
	else if (X >= 2) { return CALL(N - 1, X - 1); }
	else { return 0; }
}

int main(void) {

	cin >> N >> X;

	a[0] = 1;
	for (int i = 1; i <= N; i++) {
		a[i] = a[i - 1] * 2 + 3;
	}

	c[0] = 1;
	for (int i = 1; i <= N; i++) {
		c[i] = c[i - 1] * 2 + 1;
	}

	cout << CALL(N, X) << endl;

	//system("pause");
	return 0;
}