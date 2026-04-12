#include "bits/stdc++.h"
using namespace std;
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2175
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int C[100] = { 0 };
	for (int i = 2; i <= 9;i++) C[i + '0'] = i;
	C['T'] = 10; C['J'] = 11; C['Q'] = 12; C['K'] = 13; C['A'] = 14;
	char c;
	int leader = 0;
	while (cin >> c) {
		if (c == '#')break;
		vector<vector<string>> Card(4, vector<string>(13));
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 13;j++) {
				cin >> Card[i][j];
			}
		}
		
		int teamEW = 0, teamNS = 0;
		leader = 0;
		for (int i = 0; i < 13;i++) {
			int tokuten[4] = { 0 };
			int at = leader;
			int tokutenmax = 0;
			char suit = Card[leader][i][1];
			for (int j = 0; j < 4;j++) {

				if (Card[j][i][1] == c) {
					tokuten[j] = 15 + C[Card[j][i][0]];
				}
				else if (Card[j][i][1] == suit) {
					tokuten[j] = C[Card[j][i][0]];
				}
				if (tokutenmax < tokuten[j]) {
					tokutenmax = tokuten[j];
					at = j;
				}
			}
			if (at == 0 || at == 2) {
				teamNS++;
			}
			else {
				teamEW++;
			}
			leader = at;
			//cout << leader << endl;
		}
		if (teamNS > teamEW) {
			cout << "NS " << teamNS - 6 << endl;
		}
		else {
			cout << "EW " << teamEW - 6 << endl;
		}
	}
}