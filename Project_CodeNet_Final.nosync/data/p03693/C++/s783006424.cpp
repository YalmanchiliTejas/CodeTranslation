#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int R, G, B;

	cin >> R >> G >> B;

	int ans = R * 100 + G * 10 + B;

	if (ans % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
