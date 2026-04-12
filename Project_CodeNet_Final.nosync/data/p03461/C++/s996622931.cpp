#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
 
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
 
typedef pair<int, int> point;
 
const string FILENAME = "input";

int A, B;
int s = 2;
int d[11][11];
int X[11][11], Y[11][11], D[11][11];

int lenX[101], lenY[101], lenXY[101];
set<pair<pair<int, int>, int>> edge;

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> A >> B;
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			cin >> d[i][j];
		}
	}
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			int cnt = 0;
			X[i][j] = -1;
			for (int fX = 0; (fX * i) <= d[i][j];  ++fX) {
				for (int fY = 0; (fX * i + fY * j) <= d[i][j]; ++fY) {
					int fD = d[i][j] - fX * i - fY * j;
					bool OK = true;
					for (int a = 1; a <= A; ++a) {
						for (int b = 1; b <= B; ++b) {
							++cnt;
							if (a * fX + b * fY + fD < d[a][b]) {
								OK = false;
								a = b = 1e9;
							}
						}
					}
					if (OK) {
						X[i][j] = fX;
						Y[i][j] = fY;
						D[i][j] = fD;
						//cout << cnt << endl;
						//cout << i << ' ' << j << ' ' << fX << ' ' << fY << ' ' << fD << endl;
						fX = fY = d[i][j] + 1;
					}
				}
			}
			if (X[i][j] == -1) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	lenXY[0] = s;
	++s;
	lenXY[50] = 0;
	for (int i = 1; i < 50; ++i) {
		lenXY[i] = s++;
	}
	for (int i = 0; i < 50; ++i) {
		edge.insert({{lenXY[i + 1], s}, -2});
		edge.insert({{s, lenXY[i]}, -1});
		++s;
	}
	lenX[0] = lenY[0] = 1; 
	lenX[100] = lenY[100] = 0;
	for (int i = 1; i < 100; ++i) {
		lenX[i] = s++;
		lenY[i] = s++;
	}
	for (int i = 0; i < 99; ++i) {
		edge.insert({{lenX[i + 1], lenX[i]}, -1});
		edge.insert({{lenY[i + 1], lenY[i]}, -2});
	}
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			if (X[i][j] >= Y[i][j]) {
				edge.insert({{lenXY[50 - Y[i][j]], lenX[X[i][j] - Y[i][j]]}, D[i][j]});
			} else {
				edge.insert({{lenXY[50 - X[i][j]], lenY[Y[i][j] - X[i][j]]}, D[i][j]});
			}
		}
	}
	cout << "Possible" << endl;
	cout << s << ' ' << edge.size() << endl;
	for (auto i : edge) {
		cout << i.x.x + 1 << ' ' << i.x.y + 1 << ' ';
		if (i.y < 0) {
			if (i.y == -1) cout << "X";
			else cout << "Y";
		} else {
			cout << i.y;
		}
		cout << endl;
	}
	cout << 1 << ' ' << 2 << endl;
}
