#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	double aa, bb;
	aa = (double)a;
	bb = (double)b;
	printf("%.10f\n", (aa*bb)/(aa+bb));
	return 0;
}