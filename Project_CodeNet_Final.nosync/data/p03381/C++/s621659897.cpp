#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>

using namespace std;



int main() {
	ios::sync_with_stdio(false);

	string filename = "date";

	//ifstream cin(filename + ".in");
	//ofstream cout(filename + ".out");
	
	int n;
	cin >> n;

	vector< pair<int, int> > vec(n);
	vector< int > ans(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i].first;
		vec[i].second = i;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i) {
		if (i < n / 2) ans[vec[i].second] = vec[n / 2].first;
		else ans[vec[i].second] = vec[n / 2 - 1].first;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << "\n";
	}
	
	//system("pause");
	return 0;
}