#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define EPS 1e-10
using namespace std;
typedef long long llong;
int main() {
	vector<int>len(1000, 0);
	vector<int>e(12);
	for (int i = 0; i < 12; i++) {
		cin >> e[i];
		len[e[i]]++;
	}

	bool f = true;
	for (int i = 0; i < 12; i++) {
		if (len[e[i]] != 4 && len[e[i]] != 8 && len[e[i]] != 12)f = false;
	}

	if (f)cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}