#include <iostream>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;
typedef unsigned long long ull;
 
int n;
ull s[500], t[500], U[500], V[500];
bool u[500], v[500];
int mat[500][500];	//-1:undefined, {0, 1}
ull ans[500][500];
 
void printMat() {
	int i, j;
	rep(i, n) {
		rep(j, n) {
			cerr << mat[i][j] << " ";
		}
		cerr << endl;
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
	cerr << "construct2 : row : exist and 1 && exist or 0" << endl;
	int i, j;
	rep(i, n) {
		if (u[i]) { rep(j, n) mat[i][j] = 1; }
		else { rep(j, n) mat[i][j] = 0; }
	}
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
	cerr << "construct3 : col: exist and 1 && exist or 0" << endl;
	int i, j;
	rep(j, n) {
		if (v[j]) { rep(i, n) mat[i][j] = 1; }
		else { rep(i, n) mat[i][j] = 0; }
	}
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
	cerr << "construct4 : row, col: exist and 1" << endl;
	
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
	cerr << "construct5 : row : exist and 1" << endl;
	
	int i, j;
	int cnt[500] = {0};
	
	rep(i, n) {
		if (s[i] == 0 && u[i]) {
			rep(j, n) mat[i][j] = 1;
		}
		if (s[i] == 0 && !u[i]) {
			rep(j, n) mat[i][j] = 0;
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
			if (i == n) break;
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
	cerr << "construct6 : col: exist and 1" << endl;
	
	int i, j;
	int cnt[500] = {0};
	
	rep(j, n) {
		if (t[j] == 0 && v[j]) {
			rep(i, n) mat[i][j] = 1;
		}
		if (t[j] == 0 && !v[j]) {
			rep(i, n) mat[i][j] = 0;
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
			if (j == n) break;
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) mat[i][j] = 1;	//自信ない
	return checkMat();
}
 
bool construct9() {
	cerr << "construct 9 : only and 0, or 1. both exist row, or both exist col" << endl;
	
	int i, j;
	
	bool and0 = false;
	bool or1 = false;
	rep(i, n) {
		if (s[i] == 0 && !u[i]) and0 = true;
		if (s[i] == 1 && u[i]) or1 = true;
	}
	
	if (and0 && or1) {
		rep(i, n) {
			if (s[i] == 0 && !u[i]) {
				rep(j, n) mat[i][j] = 0;
			}
			else {
				rep(j, n) mat[i][j] = 1;
			}
		}
	}
	
	else {
		rep(j, n) {
			if (t[j] == 0 && !v[j]) {
				rep(i, n) mat[i][j] = 0;
			}
			else {
				rep(i, n) mat[i][j] = 1;
			}
		}
	}
	
	rep(i, n) rep(j, n) if (mat[i][j] == -1) mat[i][j] = 0;
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
	cerr << "construct7 : row: all and 0, col: all or 1" << endl;
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
	cerr << "construct8 : row :  all or 1,  coll : all and 0" << endl;
	
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
	cerr << "flip condition" << endl;
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
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		flip_condition();
		return true;
	}
	if (check5()) {
		bool res = construct5();
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		flip_condition();
		return true;
	}
	if (check6()) {
		bool res = construct6();
		if (!res) return false;
		rep(i, n) rep(j, n) mat[i][j] = !mat[i][j];
		flip_condition();
		return true;
	}
	
	flip_condition();
	
	if (check7()) { return construct7(); }
	if (check8()) { return construct8(); }
	
	//and0, or1のみ
	return construct9();
}
 
signed main() {
	int i, j, k;
	
	cin >> n;
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	rep(i, n) cin >> U[i];
	rep(i, n) cin >> V[i];
	
	rep(i, 64) {
		rep(j, n) u[j] = (U[j] >> i) % 2;
		rep(j, n) v[j] = (V[j] >> i) % 2;
		bool res = construct_mat();
		if (res == false) { cout << "-1" << endl; return 0; }
		rep(j, n) rep(k, n) if (mat[j][k]) ans[j][k] += ((ull)1 << i);
	}
	
	rep(i, n) {
		rep(j, n) {
			cout << ans[i][j];
			if (j + 1 < n) cout << " ";
		}
		cout << endl;
	}
	return 0;
}