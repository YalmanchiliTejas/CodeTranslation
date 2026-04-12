#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		vector<pair<int, int>>ps;
		for (int i = 0; i < N; ++i) {
			int c; cin >> c;
			if (!(i % 2)) {
				if (ps.empty()) {
					ps.emplace_back(c, 1);
				}
				else {
					if (ps.back().first == c) {
						ps.back().second++;
					}
					else {
						ps.emplace_back(c, 1);
					}
				}
			}
			else {
				if (ps.back().first == c) {
					ps.back().second++;
				}
				else {
					ps.back().first = c;
					ps.back().second++;
					if (ps.size() >= 2) {
						ps[ps.size() - 2].second += ps.back().second;
						ps.pop_back();
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < ps.size(); ++i) {
			if (!ps[i].first)ans += ps[i].second;
		}
		cout << ans << endl;
	}
	
	return 0;
}