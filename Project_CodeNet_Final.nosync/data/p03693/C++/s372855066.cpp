#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((100 * a + 10 * b + c) % 4 == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}

	return 0;
}