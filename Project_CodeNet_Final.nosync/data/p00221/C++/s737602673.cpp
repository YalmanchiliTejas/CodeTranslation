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
		int M, N; cin >> M >> N;
		if (!M)break;
		list<int>al(M);
		iota(al.begin(), al.end(), 1);
		auto it = al.begin();
		for (int i = 1; i <= N; ++i) {
			string input; cin >> input;
			string st;
			if (al.size() == 1)continue;
			if (!(i % 3)) {
				st+=("Fizz");
			}
			if (!(i % 5)) {
				st+=("Buzz");
			}
			if (st.empty()) {
				st = to_string(i);
			}

			it++;
			if (input == st) {

			}
			else {
				al.erase(prev(it));
			}
			if (it == al.end())it = al.begin();
		}
		for (auto it = al.begin(); it != al.end(); ++it) {
			cout << *it;
			if (next(it) != al.end())cout << " ";
			else cout << endl;
		}
	}
	return 0;
}