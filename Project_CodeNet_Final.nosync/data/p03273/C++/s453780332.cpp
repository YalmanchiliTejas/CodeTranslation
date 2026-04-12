#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<list>
#include<algorithm>
#include <ctype.h>
#include<deque>
using namespace std;
using ll = long long int;

int h, w;
vector<string> field;
vector<bool> row(100, true), column(100, true);
int main(void) {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		field.push_back(s);
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') {
				row[i] = false;
				column[j] = false;
			}
		}
		if (row[i])
			field.pop_back();
	}

	for (int i = w - 1; i >= 0; i--) {
		if (column[i]) {
			for (int j = 0; j < field.size(); j++) {
				field[j].erase(field[j].begin() + i);
			}
		}
	}

	for (int i = 0; i < field.size(); i++) {
		cout << field[i] << endl;
	}
	return 0;
}