#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
#include <tuple>
using namespace std;

int A, B, d[100][100], e[100][100]; bool used[100][100]; vector<tuple<int, int, int>>X;

int main() {
	cin >> A >> B;
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) cin >> d[i][j];
	}
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) {
			if (used[i][j] == true) continue;
			bool flag2 = false;
			for (int k = 0; k <= 100; k++) {
				int P1 = i*k; if (P1 > d[i][j]) continue;
				for (int l = 0; l <= 100; l++) {
					int P2 = j*l; if (P1 + P2 > d[i][j]) continue;
					int X1 = k, X2 = l, X3 = d[i][j] - P1 - P2;
					
					bool flag = true;
					for (int m = 1; m <= A; m++) {
						for (int n = 1; n <= B; n++) {
							int K = m*X1 + n*X2 + X3;
							if (d[m][n] > K) { flag = false; break; }
						}
						if (flag == false) break;
					}
					if (flag == true) {
						X.push_back(make_tuple(X1, X2, X3));
						for (int m = 1; m <= A; m++) {
							for (int n = 1; n <= B; n++) {
								int K = m*X1 + n*X2 + X3;
								if (d[m][n] == K) used[m][n] = true;
							}
						}
						flag2 = true;
						break;
					}
				}
				if (flag2 == true) break;
			}
			if (flag2 == false) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	vector<tuple<int, int, string>>G;
	for (int i = 1; i <= 100; i++) G.push_back(make_tuple(i, i + 1, "X"));
	for (int i = 102; i <= 201; i++) G.push_back(make_tuple(i, i + 1, "Y"));
	for (int i = 0; i < X.size(); i++) {
		G.push_back(make_tuple(get<0>(X[i]) + 1, 202 - get<1>(X[i]), to_string(get<2>(X[i]))));
	}
	cout << "Possible" << endl;
	cout << "202 " << G.size() << endl;
	for (int i = 0; i < G.size(); i++) {
		cout << get<0>(G[i]) << " " << get<1>(G[i]) << " " << get<2>(G[i]) << endl;
	}
	cout << "1 202" << endl;
	return 0;
}