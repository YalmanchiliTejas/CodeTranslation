#include <iostream>
using namespace std;
int main()
{
	int a[20],n,i,j,m;
	int t = 1;
	cin >> n;
	for (i = 0; i < n; ++i) {
		m = 0;
		cin >> a[i];
		if (i > 0) {
			for (j = i; j > 0; --j) {
				if (a[i] < a[j-1]) {
					m = 1;
					break;
				}
			}
			if (m == 1)continue;
			else ++t;
		}
	}
	cout << t << "\n";
	return 0;
}