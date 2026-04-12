#include <iostream>
using namespace std;

int main()
{	
	int a[5], b[5], k = 0;
	char s[6] = "ABCDE";

	cin >> a[0] >> b[0];
	int m = a[0] + b[0];

	while (m > 0) {

		for (int i = 1; i < 5; i++) {
			cin >> a[i] >> b[i];

			if (a[i] + b[i] > m) {
				k = i;
				m = a[i] + b[i];
			}
		}

		cout << s[k] << " " << m << endl;

		cin >> a[0] >> b[0];
		m = a[0] + b[0];
		k = 0;
	}
	
	return 0;
}

