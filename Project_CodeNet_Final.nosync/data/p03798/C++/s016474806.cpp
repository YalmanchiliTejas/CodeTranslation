#include <iostream>
#include <string.h>
using namespace std;

int main() {
		long n;
		char s[100000];
		bool sb[100000];
		bool animal[4][100000];

		cin >> n >> s;
		for (int a = 0; a < n; a++) {
				if (s[a] == 'o') sb[a] = 1;
				else sb[a] = 0;
		}
		animal[0][0] = 1; animal[0][1] = 1;
		animal[1][0] = 1; animal[1][1] = 0;
		animal[2][0] = 0; animal[2][1] = 1;
		animal[3][0] = 0; animal[3][1] = 0;

		for (int i = 0; i < 4; i++) {
				if (!(animal[i][0] ^ sb[0])) animal[i][n - 1] = animal[i][1];
				else animal[i][n - 1] = !animal[i][1];
				for (int j = 1; j < n - 2; j++) {
						if (!(animal[i][j] ^ sb[j])) animal[i][j + 1] = animal[i][j - 1];
						else animal[i][j + 1] = !animal[i][j - 1];
				}

				if ((!(animal[i][n - 2] ^ sb[n - 2]) == (animal[i][n - 3] == animal[i][n - 1])) &&
					(!(animal[i][n - 1] ^ sb[n - 1]) == (animal[i][n - 2] == animal[i][0]))) {
						// 条件に当てはまる場合 S, W を出力
						for (int k = 0; k < n; k++) {
								if (animal[i][k]) cout << "S";
								else cout << "W";
						}
						cout << endl;
						return 0;
				}
				}
				//条件に当てはまるものがない場合 -1を出力
				cout << -1 << endl;
				return 0;

}