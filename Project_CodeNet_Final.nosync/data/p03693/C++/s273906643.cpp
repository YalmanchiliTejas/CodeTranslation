#include <iostream>
using namespace std;

int main()
{
	int r, g, b;
	while (cin >> r >> g >> b) {
		int i = r * 100 + g * 10 + b;
		if (i % 4 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
    return 0;
}

