#include "iostream"
#include "vector"
#include "array"
#include "string"
#include "algorithm"


using namespace std;
#define rep(p,q) for(int i = p;i < q;i++)

// ab >= a + b -> a,b枚数分
// ab < a + b ab < 2 * min(a,b)
// ab < a + b ab >= 2 * min(a,b)

int main(void) {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int minAB = min(a, b);
	if (a + b <= 2 * c) {
		cout << a * x + b * y << endl;
	}
	else {
		if (c * 2 < minAB) {
			cout << c * 2 * max(x, y) << endl;
		}
		else {
			int cost = c * 2 * min(x, y);
			int left = max(x, y) - min(x, y);
			if (x > y) {
				if (a > c * 2) {
					cout << cost + c * left * 2 << endl;
				}
				else {
					cout << cost + a * left << endl;
				}
			}
			else {
				if (b > c * 2) {
					cout << cost + c * left * 2 << endl;
				}
				else {
					cout << cost + b * left << endl;
				}
			}
		}
	}
}