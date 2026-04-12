#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (long d = 0; d < (1 << n); d++) {
		cout << d << ":";

		for (int i = 0; i < n; i++) {
			if (d & (1 << i))
				cout << " " << i;
		}

		cout << endl;
	}

	return 0;
}
