#include <bits/stdc++.h>
using namespace std;

int main()
{
	char T;
	while (cin >> T, T != '#') {
		int ns = 0, ew = 0, dea = 3;
		string card[4][13];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				cin >> card[i][j];
			}
		}
		for (int i = 0; i < 13; i++) {
			int win, val = 0;
			for (int j = 0; j < 4; j++) {
				int num;
				switch (card[j][i][0]) {
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					num = card[j][i][0] - '0';
					break;
				case 'T':
					num = 10;
					break;
				case 'J':
					num = 11;
					break;
				case 'Q':
					num = 12;
					break;
				case 'K':
					num = 13;
					break;
				case 'A':
					num = 14;
					break;
				}
				if (card[j][i][1] == card[dea][i][1]) num += 20;
				if (card[j][i][1] == T) num += 40;

				if (num > val) {
					val = num;
					win = j;
				}
			}
			if (win & 1) {
				ew++;
			}
			else {
				ns++;
			}
			dea = win;
		}
		if (ew > ns) {
			cout << "EW " << ew - 6 << endl;
		}
		else {
			cout << "NS " << ns - 6 << endl;
		}
	}
	return 0;
}