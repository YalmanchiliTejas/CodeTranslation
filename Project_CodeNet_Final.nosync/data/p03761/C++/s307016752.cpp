#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int minii(int mini[], int n)
{
	int min = 10000;
	for (int i = 0; i < n; ++i) {
		if (mini[i] < min)min = mini[i];
	}
	return min;
}

int main(void)
{
	string alp("abcdefghijklmnopqrstuvwxyz");
	string s;
	int altialp[50][27];
	int min[50];
	int n;
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 27; ++j) {
			altialp[i][j] = 0;
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < s.length(); ++j) {
			for (int k = 0; k < 27; ++k) {
				if (s[j] == alp[k])altialp[i][k]++;
			}
		}
	}
	int mini;
	for (int i = 0; i < 27; ++i) {
		for (int x = 0; x < 50; ++x) {
			min[x] = 0;
		}
		for (int j = 0; j < n; ++j) {
			min[j] = altialp[j][i];
			mini = minii(min, n);
			for (int k = 0; k < mini; ++k) {
				cout << alp[i];
			}
		}
	}
	cout << endl;

	return 0;
}