#include <iostream>
#include <cassert>
#include <random>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;
typedef unsigned long long ull;

int n;
ull s[500], t[500], U[500], V[500];
int u[500], v[500];
int mat[500][500];	//-1:undefined, {0, 1}
ull ans[500][500];
bool DEBUG = false;

mt19937 mt(2525);
void random_case_F2() {
	int i;
	
	n = 2;
	rep(i, n) {
		s[i] = mt() % 2;
		t[i] = mt() % 2;
		U[i] = mt() % 2;
		V[i] = mt() % 2;
	}
}

void printMat() {
	int i, j;
	rep(i, n) {
		rep(j, n) {
			if (DEBUG) cerr << mat[i][j] << " ";
		}
		if (DEBUG) cerr << endl;
	}
}

bool checkMat() {
	int i, j;
	
	rep(i, n) {
		if (s[i] == 0) {
			rep(j, n) if (mat[i][j] == 0) break;
			if (j < n) if (u[i]) return false;
			if (j == n) if (!u[i]) return false;
		}
		else {
			rep(j, n) if (mat[i][j] == 1) break;
			if (j < n) if (!u[i]) return false;
			if (j == n) if (u[i]) return false;
		}
	}
	
	rep(j, n) {
		if (t[j] == 0) {
			rep(i, n) if (mat[i][j] == 0) break;
			if (i < n) if (v[j]) return false;
			if (i == n) if (!v[j]) return false;
		}
		else {
			rep(i, n) if (mat[i][j] == 1) break;
			if (i < n) if (!v[j]) return false;
			if (i == n) if (v[j]) return false;
		}
	}
	return true;
}

//(row: exist and 1 && col : exist or 0) ||
//(row: exist or 0  && row : exist and 1)
bool check1() {
	int i;
	
	bool flag1 = false, flag2 = false;
	rep(i, n) {
		if (s[i] == 0 && u[i]) flag1 = true;
	}
	rep(i, n) {
		if (t[i] == 1 && !v[i]) flag2 = true;
	}
	if (flag1 && flag2) return true;
	
	flag1 = false;
	flag2 = false;
	rep(i, n) {
		if (s[i] == 1 && !u[i]) flag1 = true;
	}
	rep(i, n) {
		if (t[i] == 0 && v[i]) flag2 = true;
	}
	if (flag1 && flag2) return true;
	return false;
}

//row : exist and 1 && exist or 0
bool check2() {
	int i;
	bool existAnd1 = false;
	bool existOr0 = false;
	rep(i, n) {
		if (s[i] == 0 && u[i]) existAnd1 = true;
		if (s[i] == 1 && !u[i]) existOr0 = true;
	}
	return existAnd1 && existOr0;
}

bool construct2() {
	if (DEBUG) cerr << "construct2 : row : exist and 1 && exist or 0" << endl;
	int i, j;
	rep(i, n) {
		if (u[i]) { rep(j, n) mat[i][j] = 1; }
		else { rep(j, n) mat[i][j] = 0; }
	}
	assert(checkMat() == true);
	return true;
}

//col : exist and 1 && exist or 0
bool check3() {
	int i;
	bool existAnd1 = false;
	bool existOr0 = false;
	rep(i, n) {
		if (t[i] == 0 && v[i]) existAnd1 = true;
		if (t[i] == 1 && !v[i]) existOr0 = true;
	}
	return existAnd1 && existOr0;
}

bool construct3() {
	if (DEBUG) cerr << "construct3 : col: exist and 1 && exist or 0" << endl;
	int i, j;
	rep(j, n) {
		if (v[j]) { rep(i, n) mat[i][j] = 1; }
		else { rep(i, n) mat[i][j] = 0; }
	}
	assert(checkMat() == true);
	return true;
}

//row, col: exist and 1
bool check4() {
	int i;
	bool flag1 = false;
	bool flag2 = false;
	rep(i, n) {
		if (s[i] == 0 && u[i]) flag1 = true;
		if (t[i] == 0 && v[i]) flag2 = true;
	}
	return flag1 && flag2;
}

bool construct4() {
	if (DEBUG) cerr << "construct4 : row, col: exist and 1" << endl;
	
	int i, j;
	rep(i, n) {
		if (s[i] == 0 && u[i]) { //and 1
			rep(j, n) mat[i][j] = 1;
		}
	}
	
	rep(j, n) {
		if (t[j] == 0 && v[j]) { //and 1
			rep(i, n) mat[i][j] = 1;
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) mat[i][j] = 0;
	//printMat();
	return checkMat();
}

//row : exist and1
bool check5() {
	int i;
	bool flag1 = false;
	rep(i, n) {
		if (s[i] == 0 && u[i]) flag1 = true;
	}
	return flag1;
}

bool construct5() {
	if (DEBUG) cerr << "construct5 : row : exist and 1" << endl;
	
	int i, j;
	int cnt[500] = {0};
	
	rep(i, n) {
		if (s[i] == 0) {
			if (u[i]) { rep(j, n) mat[i][j] = 1; }
			else { rep(j, n) mat[i][j] = 0; }
		}
	}
	
	i = 0;
	rep(j, n) {
		if (t[j] == 0 && !v[j]) {
			while (i < n) {
				if (s[i] == 1 && u[i] && cnt[i] < n - 1) {
					mat[i][j] = 0;
					cnt[i]++;
					break;
				}
				if (s[i] == 0 && !u[i] && cnt[i] < n) {
					mat[i][j] = 0;
					cnt[i]++;
					break;
				}
				i++;
			}
			if (i == n) {
				break;
			}
		}
	}
	
	if (DEBUG) {
		cerr << "Debug" << endl;
		rep(i, n) {
			rep(j, n) {
				cerr << mat[i][j] << " ";
			}
			cerr << endl;
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) mat[i][j] = 1;	//自信ない
	return checkMat();
}

//col : exist and1
bool check6() {
	int j;
	bool flag2 = false;
	rep(j, n) {
		if (t[j] == 0 && v[j]) flag2 = true;
	}
	return flag2;
}

bool construct6() {
	if (DEBUG) cerr << "construct6 : col: exist and 1" << endl;
	
	int i, j;
	int cnt[500] = {0};
	rep(j, n) {
		if (t[j] == 0) {
			if (v[j]) { rep(i, n) mat[i][j] = 1; }
			else { rep(i, n) mat[i][j] = 0; }
		}
	}
	
	j = 0;
	rep(i, n) {
		if (s[i] == 0 && !u[i]) {
			while (j < n) {
				if (t[j] == 1 && v[j] && cnt[j] < n - 1) {
					mat[i][j] = 0;
					cnt[j]++;
					break;
				}
				if (t[j] == 0 && !v[j] && cnt[j] < n) {
					mat[i][j] = 0;
					cnt[j]++;
					break;
				}
				j++;
			}
			if (j == n) {
				break;
			}
		}
	}
	
	if (DEBUG) {
		cerr << "Debug" << endl;
		rep(i, n) {
			rep(j, n) {
				cerr << mat[i][j] << " ";
			}
			cerr << endl;
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) mat[i][j] = 1;	//自信ない
	return checkMat();
}

bool construct9() {
	if (DEBUG) cerr << "construct 9 : only and 0, or 1. both exist row, or both exist col" << endl;
	
	int i, j;
	
	bool flag1 = false;
	bool flag2 = false;
	rep(i, n) {
		if (s[i] == 0 && !u[i]) flag1 = true;
		if (s[i] == 1 && u[i]) flag2 = true;
	}
	
	if (flag1 && flag2) {
		rep(i, n) {
			if (s[i] == 0 && !u[i]) {
				rep(j, n) mat[i][j] = 0;
			}
		}
		
		rep(i, n) {
			if (s[i] == 1 && u[i]) {
				rep(j, n) mat[i][j] = 1;
			}
		}
	}
	
	else {
		rep(j, n) {
			if (t[j] == 0 && !v[j]) {
				rep(i, n) mat[i][j] = 0;
			}
		}
		
		rep(j, n) {
			if (t[j] == 1 && v[j]) {
				rep(i, n) mat[i][j] = 1;
			}
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) assert(0);
	return checkMat();
}

//row : all and 0, col: all or 1
bool check7() {
	int i;
	rep(i, n) {
		if (!(s[i] == 0 && !u[i])) return false;
	}
	rep(i, n) {
		if (!(t[i] == 1 && v[i])) return false;
	}
	return true;
}

bool construct7() {
	if (DEBUG) cerr << "construct7 : row: all and 0, col: all or 1" << endl;
	int i, j;
	rep(i, n) {
		rep(j, n) {
			if (i == j) mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	return checkMat();
}

// row : all or 1, all and 0
bool check8() {
	int i;
	rep(i, n) {
		if (!(s[i] == 1 && u[i])) return false;
	}
	rep(i, n) {
		if (!(t[i] == 0 && !v[i])) return false;
	}
	return true;
}

bool construct8() {
	if (DEBUG) cerr << "construct8 : row :  all or 1,  coll : all and 0" << endl;
	
	int i, j;
	rep(i, n) {
		rep(j, n) {
			if (i == j) mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	return checkMat();
}

void flip_condition() {
	int i;
	
	//条件を反転
	if (DEBUG) cerr << "flip condition" << endl;
	rep(i, n) {
		s[i] = !s[i];
		u[i] = !u[i];
		t[i] = !t[i];
		v[i] = !v[i];
	}
}

//s, t, u, v --> mat
bool construct_mat() {
	int i, j;
	
	if (n == 1) {
		mat[0][0] = 0;
		if (checkMat()) return true;
		mat[0][0] = 1;
		if (checkMat()) return true;
		return false;
	}
	
	if (check1()) return false;
	rep(i, n) rep(j, n) mat[i][j] = -1;
	
	if (check2()) {
		return construct2();
	}
	if (check3()) {
		return construct3();
	}
	if (check4()) {
		return construct4();
	}
	if (check5()) {
		return construct5();
	}
	if (check6()) {
		return construct6();
	}
	
	//条件を反転してみる
	flip_condition();
	
	if (check4()) {
		bool res = construct4();
		flip_condition();
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		return true;
	}
	if (check5()) {
		bool res = construct5();
		flip_condition();
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		return true;
	}
	if (check6()) {
		bool res = construct6();
		flip_condition();
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		return true;
	}
	
	flip_condition();
	
	if (check7()) { return construct7(); }
	if (check8()) { return construct8(); }
	
	//and0, or1のみ
	return construct9();
}

bool solve() {
	int i, j, k;
	
	rep(i, n) rep(j, n) ans[i][j] = 0;
	
	int B = 64;	//ストレステスト時は1, サブミット時は64に変える.
	
	rep(i, B) {
		rep(j, n) u[j] = (U[j] >> i) % 2;
		rep(j, n) v[j] = (V[j] >> i) % 2;
		bool res = construct_mat();
		if (res == false) { return false; }
		rep(j, n) rep(k, n) if (mat[j][k]) ans[j][k] += ((ull)1 << i);
	}
	
	/*rep(i, n) {
		rep(j, n) {
			cout << ans[i][j];
			if (j + 1 < n) cout << " ";
		}
		cout << endl;
	}*/
	return true;
}

bool checkAns() {
	int i, j;
	rep(i, n) {
		ull bitAnd = ans[i][0];
		ull bitOr = ans[i][0];
		rep(j, n) {
			bitAnd &= ans[i][j];
			bitOr |= ans[i][j];
		}
		if (s[i] == 0) { if (bitAnd != U[i]) return false; }
		if (s[i] == 1) { if (bitOr != U[i]) return false; }
	}
	
	rep(j, n) {
		ull bitAnd = ans[0][j];
		ull bitOr = ans[0][j];
		rep(i, n) {
			bitAnd &= ans[i][j];
			bitOr |= ans[i][j];
		}
		if (t[j] == 0) { if (bitAnd != V[j]) return false; }
		if (t[j] == 1) { if (bitOr != V[j]) return false; }
	}
	return true;
}

//U[i], V[i]が0か1の場合
bool allSearch(int y, int x) {
	if (y >= n) { return checkAns(); }
	if (x >= n) { return allSearch(y + 1, 0); }
	
	ans[y][x] = 0;
	if (allSearch(y, x + 1)) return true;
	
	ans[y][x] = 1;
	if (allSearch(y, x + 1)) return true;
	return false;
}

//0, 1の問題を前提に設計
void printCase() {
	cerr << "n = " << n << endl;
	
	int i, j;
	
	cerr << "______| ";
	rep(j, n) {
		if (t[j] == 0) {
			cerr << "and " << V[j] << " ";
		}
		else {
			cerr << "or " << V[j] << " ";
		}
	}
	cerr << endl;
	
	rep(i, n) {
		if (s[i] == 0) {
			cerr << "and " << U[i] << endl;
		}
		else {
			cerr << "or " << U[i] << " " << endl;
		}
	}
	cerr << endl;
}

void printAns() {
	int i, j;
	
	if (DEBUG) cerr << "ans" << endl;
	rep(i, n) {
		rep(j, n) {
			cout << ans[i][j];
			if (j + 1 < n) cout << " ";
		}
		cout << endl;
	}
}

void random_checker() {
	int i, j;
	
	for (int t = 0; t < 10000; t++) {
		if (t % 100 == 0) cerr << "t = " << t << endl;
		random_case_F2();
		bool res = solve();
		//cerr << "res = " << res << endl;
		//cerr << "solve = " << solve() << endl;
		
		if (res == false) {
			
			rep(i, n) rep(j, n) ans[i][j] = 0;
			bool res2 = allSearch(0, 0);
			
			if (res2) {
				cerr << "Wrong Answer[" << t << "]" << endl;
				
				printCase();
				cerr << endl;
				
				//デバッグ出力用
				DEBUG = true;
				cerr << "solve.return = " << solve() << endl;
				
				rep(i, n) rep(j, n) ans[i][j] = 0;
				res2 = allSearch(0, 0);
				
				printAns();
				break;
			}
		}
		else {
			if (checkAns() == false) {
				cout << "Very Wrong" << endl;
				printCase();
				printAns();
				break;
			}
		}
	}
}

void input() {
	cin >> n;
	int i;
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	rep(i, n) cin >> U[i];
	rep(i, n) cin >> V[i];
}

signed main() {
	//random_checker();
	input();
	bool res = solve();
	if (!res) { cout << -1 << endl; }
	else { printAns(); }
	return 0;
}