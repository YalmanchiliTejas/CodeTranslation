#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((g * 10 + b) % 4 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
