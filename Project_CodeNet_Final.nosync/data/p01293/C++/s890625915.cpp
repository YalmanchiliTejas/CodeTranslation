#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

map<char, int>nummp;
map<char, int>suitmp;
int main() {
	for (int i = 2; i <= 9; ++i) {
		nummp['0' + i] = i;
	}
	nummp['T'] = 10;
	nummp['J'] = 11;
	nummp['Q'] = 12;
	nummp['K'] = 13;
	nummp['A'] = 14;


	while (1) {
		char tramp; cin >> tramp;
		if (tramp == '#')break;
		vector<vector<pair<int, char>>>cards(4, vector<pair<int, char>>(13));
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 13; ++j) {
				string st; cin >> st;
				const int num = nummp[st[0]];
				cards[i][j] = make_pair(num, st[1]);
			}
		}
		int fp = 0;
		vector<int>points(4);
		for (int trick = 0; trick < 13; ++trick) {
			char fst = cards[fp][trick].second;
			vector<int>powers(4);
			for (int p = 0; p < 4; ++p) {
				int apower = cards[p][trick].first;
				if (cards[p][trick].second == tramp)apower += 10000;
				if (cards[p][trick].second == fst)apower += 100;
				powers[p] = apower;
			}
			int winner = max_element(powers.begin(), powers.end())-powers.begin();
			points[winner]++;
			fp = winner;

		}
		if (points[0] + points[2]>6) {
			cout << "NS " << points[0] + points[2] - 6 << endl;
		}
		else {
			cout << "EW " << 7-(points[0] + points[2]) << endl;

		}

	}
	return 0;
}