#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

#include <cstdio>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;


	int money = 0;
	// Aピザ1枚最適
	bool buyA = true;
	if (C * 2 < A) {
		buyA = false;
	}

	// Bピザ1枚最適
	bool buyB = true;
	if (C * 2 < B) {
		buyB = false;
	}

	// AピザBピザ1枚ずつ最適
	bool buyAB = true;
	if (A + B < C * 2) {
		buyAB = false;
	}

	if (buyAB) {
		if (X < Y) {
			money += X * C * 2;
			Y = Y - X;
			X = 0;
		}
		else {
			money += Y * C * 2;
			X = X - Y;
			Y = 0;
		}
	}

	if (buyA) {
		money += X * A;
		X = 0;
	}
	else {
		money += X * C * 2;
		X = 0;
	}


	if (buyB) {
		money += Y * B;
		Y = 0;
	}
	else {
		money += Y * C * 2;
		Y = 0;
	}

	cout << money << '\n';


	return 0;
}