#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c;
	cin >> a >> b >> c;
	if ((10 * b + c) % 4 == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}