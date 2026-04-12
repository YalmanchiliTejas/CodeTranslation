#include <iostream>
#include <cstdio>
using namespace std;

int r1, r2;

int main() {
	cin >> r1 >> r2;
	printf("%.14f\n", 1.0 / (1.0 / r1 + 1.0 / r2));
	return 0;
}