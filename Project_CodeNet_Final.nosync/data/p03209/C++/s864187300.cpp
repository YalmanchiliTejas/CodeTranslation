#include <iostream>
using namespace std;

int main()
{
	int n;
	long long x, p = 0;

	cin >> n >> x;

	while (n >= 0) {
		if (x >= (1ull << (n + 1)) - 1) {
			p += 1ull << n;
			x -= (1ull << (n + 1)) - 1;
		}
		else if (x > 0)
			x--;

		n--;
	}

	cout << p << endl;
	
	return 0;
}