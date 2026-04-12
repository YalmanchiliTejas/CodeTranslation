#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
typedef pair<int, int> P;
vector<string> mp;
vector<P> wp;

int comp(P a, P b) {
	return a.second > b.second;
}

int main() {
	bool first = true;
	while (true) {
		cin >> N;
		if (N == 0) {return 0;}
		if (!first) {
			cout << endl;
		}
		first = false;
		mp.clear();
		wp.clear();
		for (int i = 0; i < N; i++) {
			string country;
			cin >> country;
			int w, d, l;
			cin >> w >> l >> d;
			mp.push_back(country);
			wp.push_back(P(i, 3 * w + d));
		}
		stable_sort(wp.begin(), wp.end(), comp);
		for (int i = 0; i < wp.size(); i++) {
			cout << mp[wp[i].first] << "," << wp[i].second << endl;
		}
	}
}