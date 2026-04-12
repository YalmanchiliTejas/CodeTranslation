#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <queue>
#include <exception>
#include <cmath>
#include <numeric>
#include <map>
#include <algorithm>
#include <bitset>
#include <set>
#include <functional>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

using namespace std;
typedef long long int lint;
typedef vector<vector<int> > matrix;

int dy[5] = { -1, 0, 0, 0, 1 };
int dx[5] = { 0, -1, 0, 1, 0 };

void print(matrix& mat) {
	REP(y, 10) {
		REP(x, 10) {
			if (x) cout << " ";
			cout << mat[y][x];
		}
		cout << endl;
	}
}

matrix mk_matrix(int n) {
	matrix mat(n);
	REP(i, n) {
		mat[i] = vector<int>(10, 0);
	}
	return mat;
}

void push(matrix& mat, int y, int x) {
	REP(i, 5) {
		int nx = x + dx[i];
		if (nx < 0 || nx >= 10) continue;
		int ny = y + dy[i];
		if (ny < 0 || ny >= 10) continue;
		mat[ny][nx] ^= 1;
	}
}

void solve(matrix& mat) {
	//?????????????????¨????????????????????????
	REP(i, 1024) {
		matrix mat_tmp = mat;
		matrix pushed = mk_matrix(10);
		int tmp = i;
		REP(j, 10) {
			if (!tmp) break;
			if (tmp & 1) {
				push(mat_tmp, 0, j);
				pushed[0][j] = 1;
				//print(mat_tmp);
			}
			tmp >>= 1;
		}

		FOR(y, 1, 10) {
			REP(x, 10) {
				if (mat_tmp[y - 1][x]) {
					push(mat_tmp, y, x);
					pushed[y][x] = 1;
					//print(mat_tmp);
				}
			}
		}
		//cout << i << endl;
		//print(mat_tmp);
		if (find(mat_tmp[9].begin(), mat_tmp[9].end(), 1) == mat_tmp[9].end()) {
			print(pushed);
			//cout << "solved." << endl;
			return;
		}
	}
}

bool AOJ0131()
{
	matrix mat = mk_matrix(10);
	REP(i, 10) {
		REP(j, 10) {
			cin >> mat[i][j];
		}
	}

	solve(mat);

	return true;
}

int main()
{
	int n;
	cin >> n;
	REP(i, n) AOJ0131();

	return 0;
}