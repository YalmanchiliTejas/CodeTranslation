#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, i, j, k, d[51][27] = {};
	string s;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < s.size(); j++) {
			for (k = 0; k < 27; k++) {
				if (s[j] == 'a' + k) {
					d[i][k]++;
				}
			}
		}
	}

	for (i = 0; i < 27; i++) {
		d[50][i] = d[0][i];
		for (j = 1; j < n; j++) {
			d[50][i] = min(d[50][i], d[j][i]);
		}
	}

	for (i = 0; i < 27; i++) {
		for (j = 0; j < d[50][i]; j++) {
			printf("%c", 'a' + i);
		}
	}
	printf("\n");

	return 0;
}