#include <iostream>
using namespace std;

int main() {
	int r, g, b, val;
	scanf("%d%d%d", &r, &g, &b);
	
	val = r * 100 + g * 10 + b * 1;
	
	printf("%s", val % 4 == 0 ? "YES" : "NO");
	return 0;
}