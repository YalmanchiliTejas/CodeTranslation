#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	map<char, size_t> tmp1, tmp2;
	string s;
	for (char i = 'a'; i <= 'z'; ++i) {
		tmp1.insert(make_pair(i, 50));
		tmp2.insert(make_pair(i, 0));
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (char j = 'a'; j <= 'z'; ++j) tmp2.at(j) = 0;
		cin >> s;
		for (auto& x : s) ++tmp2.at(x);
		for (char j = 'a'; j <= 'z'; ++j) tmp1.at(j) = min(tmp1.at(j), tmp2.at(j));
	}
	for (char i = 'a'; i <= 'z'; ++i) {
		for (size_t j = 0; j < tmp1.at(i); ++j) cout << i;
	}
}