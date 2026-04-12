#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	vector<pair<int, int>>vs(5);
	while (cin >> vs[0].first >> vs[0].second) {
		if (vs[0].first == 0)break;
		for (int i = 1; i < 5; ++i) {
			cin >> vs[i].first >> vs[i].second;
		}
		int ans=0;
		int sum = 0;
		for (int i = 0; i < 5; ++i) {
			if (sum < vs[i].first + vs[i].second) {
				sum = vs[i].first + vs[i].second;
				ans = i;
			}
		}
		cout << char('A' + ans) << " " << sum << endl;
	}
	return 0;
}