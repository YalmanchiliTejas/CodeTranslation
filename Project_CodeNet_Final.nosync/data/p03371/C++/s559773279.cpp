#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	if (a + b < 2 * c){
		cout << a * x + b * y << endl;
	}
	else{
		int minNum = x < y ? x : y;
		int cost = minNum * 2 * c;
		if (x > y){
			if (a > 2 * c){
				cost += 2 * c * (x - minNum);
			}
			else{
				cost += a * (x - minNum);
			}
		}
		else{
			if (b > 2 * c){
				cost += 2 * c * (y - minNum);
			}
			else{
				cost += b * (y - minNum);
			}
		}
		cout << cost << endl;
	}
}