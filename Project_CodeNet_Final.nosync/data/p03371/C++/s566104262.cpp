#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	//ABの方が得
	if (a + b > 2 * c) {
		int min = (x < y) ? x : y;
		int max = (x > y) ? x : y;
		int minp = a*(x - min) + b*(y - min) + 2*c*min;
		int maxp = 2*c*max;
		cout << ((minp < maxp) ? minp : maxp) << endl;
	} 
	//それぞれ買った方が得
	else {
		cout << a*x + b*y << endl;
	}

}