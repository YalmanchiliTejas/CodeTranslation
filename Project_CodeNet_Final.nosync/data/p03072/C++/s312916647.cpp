#include <iostream>
using namespace std;

int main()
{
	int n, hm = 0, m = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;

		if (hm <= h) {
			hm = h;
			m++;
		}
	}

	cout << m << endl;
	
	return 0;
}
