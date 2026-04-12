#include<iostream>
#include<vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include<string>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int ue = 1, sita = 6, temae = 2, oku = 5, migi = 3, hidari = 4;
		int score = 1;
		for (int i = 0; i < n; ++i) {
			int keep = 0;
			string move;
			cin >> move;
			if (move == "South") {
				keep = ue;
				ue = oku;
				oku = sita;
				sita = temae;
				temae = keep;
			}
			else if (move == "North") {
				keep = ue;
				ue = temae;
				temae = sita;
				sita = oku;
				oku = keep;
			}
			else if (move == "East") {
				keep = ue;
				ue = hidari;
				hidari = sita;
				sita = migi;
				migi = keep;
			}
			else if (move == "West") {
				keep = ue;
				ue = migi;
				migi = sita;
				sita = hidari;
				hidari = keep;
			}
			else if (move == "Right") {
				keep = temae;
				temae = migi;
				migi = oku;
				oku = hidari;
				hidari = keep;
			}
			else {
				keep = temae;
				temae = hidari;
				hidari = oku;
				oku = migi;
				migi = keep;
			}
			score += ue;
		}
		cout << score << endl;
	}
	return 0;
}