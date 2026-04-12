#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#define PI 3.14159265359
using namespace std;

int main()
{
	int m;
	char s[4][100001];
	char ox[100001];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> ox[i];
	}

	if (ox[0] == 'o') {
		s[0][0] = 'S';
		s[0][1] = 'S';
		s[1][0] = 'S';
		s[1][1] = 'W';
		s[2][0] = 'W';
		s[2][1] = 'W';
		s[3][0] = 'W';
		s[3][1] = 'S';
	}
	if (ox[0] == 'x') {
		s[0][0] = 'S';
		s[0][1] = 'W';
		s[1][0] = 'S';
		s[1][1] = 'S';
		s[2][0] = 'W';
		s[2][1] = 'S';
		s[3][0] = 'W';
		s[3][1] = 'W';
	}
	int i = m - 1;
	for (int n = 0; n < 4; ++n) {
		for (i = 1; i < m; ++i) {
			if (ox[i] == 'x'&&s[n][i] == 'S'&&s[n][i - 1] == 'W')s[n][i + 1] = 'S';
			else if (ox[i] == 'x'&&s[n][i] == 'S'&&s[n][i - 1] == 'S')s[n][i + 1] = 'W';
			else if (ox[i] == 'o'&&s[n][i] == 'S'&&s[n][i - 1] == 'S')s[n][i + 1] = 'S';
			else if (ox[i] == 'o'&&s[n][i] == 'S'&&s[n][i - 1] == 'W')s[n][i + 1] = 'W';
			else if (ox[i] == 'o'&&s[n][i] == 'W'&&s[n][i - 1] == 'S')s[n][i + 1] = 'W';
			else if (ox[i] == 'o'&&s[n][i] == 'W'&&s[n][i - 1] == 'W')s[n][i + 1] = 'S';
			else if (ox[i] == 'x'&&s[n][i] == 'W'&&s[n][i - 1] == 'S')s[n][i + 1] = 'S';
			else if (ox[i] == 'x'&&s[n][i] == 'W'&&s[n][i - 1] == 'W')s[n][i + 1] = 'W';
		}
		if (s[n][i] == s[n][0] && ((s[n][0] == 'S'&&ox[0] == 'o' &&s[n][1] == s[n][m - 1]) || (s[n][0] == 'S'&&ox[0] == 'x'&&s[n][1] != s[n][m - 1]) || (s[n][0] == 'W'&&ox[0] == 'x'&&s[n][1] == s[n][m - 1]) || (s[n][0] == 'W'&&ox[0] == 'o'&&s[n][1] != s[n][m - 1]))) {
			for (int j = 0; j < m; ++j) {
				cout << s[n][j];
			}
			cout << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}