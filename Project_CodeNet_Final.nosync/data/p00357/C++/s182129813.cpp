#include <iostream>

using namespace std;

int n;

bool tansaku(int tt[])
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = max > i + tt[i] ? max : i + tt[i];
		if ( max >= n ) {
			return true;
		} else if ( i + 1 > max ) {
			break;
		}
	}
	return false;
}


int main()
{
	int tt1[300000];
	int tt2[300000];
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		tt1[i] = t / 10;
		tt2[n - 1 - i] = t / 10;
	}
	if (tansaku(tt1) && tansaku(tt2) ) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	return 0;
}

