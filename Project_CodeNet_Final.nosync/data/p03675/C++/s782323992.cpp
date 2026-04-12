#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
vector<int> v, ans;

int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int k, mode = 0;

	k = n;

	for (int i = 0; i < n; ++i) {
		cout << v[k-1];
		
		if (i == n - 1) {
			cout << endl;
			break;
		}
		else cout << " ";

		if (mode == 0 && k > 2) k -= 2;
		else if (mode == 0 && k == 2) {
			k = 1;
			mode = 1;
		}
		else if (mode == 0 && k == 1) {
			k = 2;
			mode = 1;
		}
		else {
			k += 2;
		}
	}

    return 0;
}

