#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
	const int N = 100000;
	int n;
	string s;
	//string t;
	//string j;
	char first[4][3] = {"SS", "SW", "WS", "WW"};

	cin >> n;
	cin >> s;

	string t(n, 'a');
	string j(n, 'a');
	// 最初の2匹を決めれば、他の配置は自ずと決まる
	for (int k = 0; k < 4; k++) {
		t[0] = first[k][0];
		t[1] = first[k][1];
		for (int i = 1; i < n - 1; i++) {
			j[i] = s[i];
			if (t[i] == 'S') {
				if (j[i] == 'o') {
					t[i + 1] = t[i - 1];
				} else {
					if (t[i - 1] == 'S') t[i + 1] = 'W';
					else t[i + 1] = 'S';
				}
			} else {
				if (j[i] == 'x') {
					t[i + 1] = t[i - 1];
				} else {
					if (t[i - 1] == 'S') t[i + 1] = 'W';
					else t[i + 1] = 'S';
				}
			}
		}
		if (t[n - 1] == 'S') {
			if (t[n - 2] == t[0]) j[n - 1] = 'o';
			else j[n - 1] = 'x';
		} else {
			if (t[n - 2] == t[0]) j[n - 1] = 'x';
			else j[n - 1] = 'o';
		}
		if (t[0] == 'S') {
			if (t[n - 1] == t[1]) j[0] = 'o';
			else j[0] = 'x';
		} else {
			if (t[n - 1] == t[1]) j[0] = 'x';
			else j[0] = 'o';
		}
		//cout << j << endl;
		if (j == s) {
			cout << t << endl;
			//printf("%s\n", t);
			return (0);
		}
	}
	cout << "-1" << endl;

	return (0);
}