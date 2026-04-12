#include <algorithm>
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;

void Show(vector<vector<bool>> S) {
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S[i].size(); j++) {
			if ((S[i][j])) {
				cout << '.';
			} else {
				cout << '#';
			}
		}
		cout << endl;
	}
}
int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int All_C = max(X, Y)*C * 2;
	int With_C = min(X, Y)*C * 2;
	With_C += (X > Y) ? (X - Y)*A : (Y - X)*B;
	int Palarell = A * X + B * Y;
	int Min = min(min(All_C, With_C), Palarell);
	cout << Min << endl;
}
