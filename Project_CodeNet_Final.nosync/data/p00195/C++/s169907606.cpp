#include "bits/stdc++.h"
using namespace std;

int main() {
	vector<pair<int, int> > pairs;
	string s = "ABCDE";

	bool ok = true;
	
	while (ok) {
		int max_v = 0, max_n = 0;

		for (int i = 0; i < 5; ++i) {
			int val1, val2;
			cin >> val1 >> val2;

			if (val1 == 0 && val2 == 0) {
				ok = false;
				break;
			}

			int all = val1 + val2;

			if (all > max_v) {
				max_v = all;
				max_n = i;
			}
		}

		if(ok != false) pairs.push_back(make_pair(max_n, max_v));
	}

	for (int i = 0; i < pairs.size(); ++i) {
		cout << s[pairs[i].first] << " " << pairs[i].second << endl;
	}

}

