#include <iostream>
int main() {
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	r = r * 100 + g * 10 + b;
	if (r % 4)std::cout << "NO";
	else std::cout << "YES";
	return 0;

}