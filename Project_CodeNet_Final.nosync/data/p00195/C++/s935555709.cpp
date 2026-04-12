#include <iostream>
#include <string>

using namespace std;

int main() {
	string a = "ABCDE";
	int p, q;
	while (cin >> p >> q) {
		if (p == 0 && q == 0) {
			break;
		}
		int max = p+q;
		char maxn = a[0];
		for (int i = 1; i < a.size(); i++) {
			cin >> p >> q;
			if (max < p+q) {
				max = p+q;
				maxn = a[i];
			}
		}
		cout << maxn << " " << max << endl;
	}
	return 0;
}