#include <iostream>
#include <string.h>
using namespace std;

void a_rgb_cards(void) {
	int r, g, b;
	cin >> r >> g >> b;

	int sum = 100 * r + g * 10 + b;
	if ((sum & 0x3) == 0x0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main()
{
	a_rgb_cards();
    return 0;
}