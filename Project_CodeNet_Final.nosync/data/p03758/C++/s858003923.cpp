#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> beet;

vector<beet> latte;

int main()
{
	int cnt = 0;

	int po;
	cin >> po;

	for (int i = 0; i < po; ++i) {
		for (int j = i + 1; j < po; ++j) {
			
			cout << "? ";

			for (int k = 0; k < po; ++k) {
				if (k == i || k == j) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}

			cout << endl;

			int d;
			cin >> d;

			if (d) {
				latte.push_back(beet(i, j));
			}
		}
	}

	cout << "!";
	for (int i = 0; i < latte.size(); ++i) {
		printf(" (%d,%d)", latte[i].first, latte[i].second);
	}
	cout << endl;
}
