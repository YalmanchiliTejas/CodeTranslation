#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <functional>
#include <chrono>
#include <time.h>
using namespace std;

int main()
{
	int n; cin >> n;
	string s = string(n, '0');

	vector<vector<int>>E(n);
	for (int i = 0; i < n; i++) {
		s[i]++;
		for (int j = i+1; j < n; j++) {
			s[j]++;
			cout << "? " << s << endl;
			int d; cin >> d;
			if (d == 1)E[i].push_back(j);
			s[j]--;
		}
		s[i]--;
	}

	cout << "!";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < E[i].size(); j++) {
			cout << " (" << i << "," << E[i][j] << ")";
		}
	}
	cout << endl;

	return 0;
}
