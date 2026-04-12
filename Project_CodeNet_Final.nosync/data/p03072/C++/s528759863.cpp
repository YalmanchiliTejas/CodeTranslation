#include <iostream>
using namespace std;

const int N = 2e6;

int a[N];

main() {
	clog << "Ready\n";
	
	int n;
	cin >> n;
	
	int cnt = 0;

	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++ i) {
		bool ok = false;
		for (int j = 1; j < i; ++ j)
			if (a[j] > a[i])
				ok = true;
		cnt += !ok;
	}

	cout << cnt;
	
	cerr << '\n';

	return 0;
}
