#include<iostream>
using namespace std; 
int main() {
	int a, b, c, x, y,cost=0;
	cin >> a >> b >> c >> x >> y;
	if ((a + b) > 2 * c) {
		if (x > y) {
			cost = 2 * c*y;
			x -= y;
			if (a > 2 * c)
				cost += 2 * c*x;
			else
				cost += x * a;

		}
		else
		{
			cost = 2 * c*x;
			y -= x;
			if (b > 2 * c)
				cost += 2 * c*y;
			else
				cost += y * b;
		}
	}
	else
		cost = a * x + b * y;
	cout << cost<<endl;
	//system("pause");
	return 0;
}