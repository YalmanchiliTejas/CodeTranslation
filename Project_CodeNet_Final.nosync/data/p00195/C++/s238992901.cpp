#include <iostream>

using namespace std;
char shops[] = {'A', 'B', 'C', 'D', 'E'};

int main () {
	int a, b, maxTotal;
	char maxShop;
	while (maxShop = shops[0], cin >> a >> b, a || b) {
		maxTotal = a + b;
		for (int i = 1; i < 5; i++) {
			cin >> a >> b;
			if (a + b > maxTotal) {
				maxTotal = a + b;
				maxShop = shops[i];
			}
		}
		cout << maxShop << ' ' << maxTotal << endl;
	}
	return 0;
}