#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	bool find;
	int res,n,l,r;
	while (cin >> n >> l >> r||n,l,r) {
		vector<int> A(n);
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		res = 0;
		for (int num = l; num < r+1; ++num) {
			find = false;
			for (int i = 0; !find && i < n; ++i) {
				if (num%A[i] == 0) {
					find = true;
					if (i%2 == 0) {
						++res;
					}
				}
			}
			if (!find && n%2 == 0) {
				++res;
			}
		}
		cout << res << endl;
	}
	return 0;
}

