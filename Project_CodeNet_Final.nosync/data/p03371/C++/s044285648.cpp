/* ABC095 - C
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	bool first = true;
	int current = 0;
	int z = max(X, Y) * 2;

	for (int i = 0; i <= z; i += 2) {
		int x = max(0, X - (i / 2));
		int y = max(0, Y - (i / 2));

		int total = A * x + B * y + C * i;
		if (first) {
			first = false;
			current = total;
		} else {
			if (total < current) {
				current = total;
			}
		}

	}

	cout << current << endl;

	return 0;
}

