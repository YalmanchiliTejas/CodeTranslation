#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int sum = 0;
	int de = (x > y) ? x - y : y - x;
	if (a + b <= 2 * c) {
		cout << a * x + b * y << endl;
		return 0;
	}
	else {
		if (x > y) {
			if(a*de <= 2*c*de)
				sum += 2 * c * y + a * de;
			else
				sum += 2 * c * (y +de);

		}
		else {
			if (b*de <= 2 * c*de)
				sum += 2 * c * x + b * de;
			else
				sum += 2 * c*(x + de);
		}
	}
	cout << sum << endl;


	return 0;
}