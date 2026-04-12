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
	int N;
	cin >> N;
	while (1) {
		vector<pair<int, string>>ps;
		for (int i = 0; i < N; ++i) {
			string st; int a, b, c; cin >> st >> a >> b >> c;
			int score = a * 3 + c;
			ps.emplace_back(score*100-i+99, st);
		}
		sort(ps.begin(), ps.end(),greater<pair<int,string>>());
		for (auto p : ps) {
			cout << p.second << "," << p.first/100 << endl;
		}
		cin >> N;
		if (!N)break;
		cout << endl;
	}
	return 0;
}