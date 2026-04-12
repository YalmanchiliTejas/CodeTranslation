#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int i;
	for (i = n - 1; i >= 0; i -= 2) {
		if (i != n - 1)cout << " ";
		cout << a[i];
	}
	i += 2;
	for (i = i^1; i < n; i += 2) {
		cout << " ";
		cout << a[i];
	}
	cout << endl;


    return 0;
}

