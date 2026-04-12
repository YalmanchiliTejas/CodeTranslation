#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
typedef pair<P, string> E;

int f[101][101];
int d[11][11];
int main() {
	int A, B;
	cin >> A >> B;
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) cin >> d[i][j];
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int x = 1; x <= A; x++) {
				for (int y = 1; y <= B; y++) {
					f[i][j] = max(f[i][j], d[x][y] - x * i - y * j);
				}
			 }
		}
	}
	for (int x = 1; x <= A; x++) {
		for (int y = 1; y <= B; y++) {
			int D = 1 << 30;
			for (int i = 0; i <= 100; i++) {
				for (int j = 0; j <= 100; j++) {
					D = min(D, x*i + y * j + f[i][j]);
				}
			}
			if (D != d[x][y]) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}

	cout << "Possible" << endl;
	vector<E> edge;
	for (int i = 0; i < 100; i++) {
		edge.emplace_back(P(1 + i, 1 + i + 1), "X");
		edge.emplace_back(P(202 - i, 202 - i - 1), "Y");
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			edge.emplace_back(P(1 + i, 102 + j), to_string(f[i][j]));
		}
	}
	cout << 202 << " " << edge.size() << endl;
	for (E e : edge) {
		cout << e.first.first << " " << e.first.second << " " << e.second << endl;
	}
	cout << "1 102" << endl;
}