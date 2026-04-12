#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int main()
{	
	int n;

	cin >> n;

	while (n > 0) {
		int a[15][15];

		memset(a, 0, sizeof(a));

		int p = n / 2 + 1, q = n / 2;

		a[p][q] = 1;

		for (int i = 2; i <= n * n; i++) {
			p = (p + 1) % n;
			q = (q + 1) % n;

			if(a[p][q] == 0)
				a[p][q] = i;
			else {
				p = (p + 1) % n;
				q = (q + n - 1) % n;
				a[p][q] = i;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << setw(4) << a[i][j];
			cout << endl;
		}

		cin >> n;
	}

	return 0;
}

