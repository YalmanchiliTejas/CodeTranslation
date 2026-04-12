#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

#define sheep 'S'
#define wolf 'W'
#define T 'o'
#define F 'x'

char ring[4][100000];

int main() {
	ll n;
	string s;
	cin >> n;
	cin >> s;
	ring[0][1]= sheep;
	ring[1][1] = wolf;
	ring[2][1] = sheep;
	ring[3][1] = wolf;
	for (int i = 0; i < 2; i++) {
		ring[i][0] = sheep;
		ring[i + 2][0] = wolf;
	}
	for (ll i = 1; i < n - 1; i++) {
		if (s[i] == T) {
			for (int j = 0; j < 4; j++) {
				if (ring[j][i] == sheep) {
					ring[j][i + 1] = ring[j][i - 1];
				}
				else  {
					if (ring[j][i - 1] == sheep)ring[j][i + 1] = wolf;
					else ring[j][i + 1] = sheep;
				}
			}
		}
		else  {
			for (int j = 0; j < 4; j++) {
				for (int j = 0; j < 4; j++) {
					if (ring[j][i] == wolf) {
						ring[j][i + 1] = ring[j][i - 1];
					}
					else {
						if (ring[j][i - 1] == sheep)ring[j][i + 1] = wolf;
						else ring[j][i + 1] = sheep;
					}
				}
			}
		}
	}
	bool res[4];
	for (int i = 0; i < 4; i++) {
		if (s[n - 1] == T) {
			if (ring[i][n - 1] == sheep) {
				if (ring[i][n - 2] == ring[i][0])res[i] = true;
				else res[i] = false;
			}
			else {
				if (ring[i][n - 2] != ring[i][0])res[i] = true;
				else res[i] = false;
			}
		}
		else {
			if (ring[i][n - 1] == wolf) {
				if (ring[i][n - 2] == ring[i][0])res[i] = true;
				else res[i] = false;
			}
			else {
				if (ring[i][n - 2] != ring[i][0])res[i] = true;
				else res[i] = false;
			}
		}
	}	
	for (int i = 0; i < 4; i++) {
		if (res[i]) {
			if (s[0] == T) {
				if (ring[i][0] == sheep) {
					if (ring[i][n - 1] == ring[i][1])res[i] = true;
					else res[i] = false;
				}
				else {
					if (ring[i][n - 1] != ring[i][1])res[i] = true;
					else res[i] = false;
				}
			}
			else {
				if (ring[i][0] == wolf) {
					if (ring[i][n - 1] == ring[i][1])res[i] = true;
					else res[i] = false;
				}
				else {
					if (ring[i][n - 1] != ring[i][1])res[i] = true;
					else res[i] = false;
				}
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		if (res[i]) {
			for (ll j = 0; j < n; j++) {
				printf("%c", ring[i][j]);
			}
			printf("\n");
			flag = false;
			break;
		}
	}
	if (flag)cout << -1 << endl;
}

