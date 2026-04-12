#include <iostream>
#include <string>
using namespace std;
int main(void) {
	int x, y, z, cnt = 1;
	cin >> x >> y >> z;
	x -= y + 2 * z;
	
	while (1) {
		x -= y + z;
		if (x < 0) break;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}