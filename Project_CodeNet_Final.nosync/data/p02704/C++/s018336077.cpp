#include <iostream>
#include <vector>
using namespace std;

long long N;
unsigned long long S[1 << 18], T[1 << 18], U[1 << 18], V[1 << 18];
unsigned long long Answer[509][509];

// 計算用
int forced[509][509];

bool hantei(vector<vector<int>> Z, vector<int> A1, vector<int> B1, vector<int> A2, vector<int> B2) {
	for (int i = 0; i < N; i++) {
		int ands = 1, ors = 0;
		for (int j = 0; j < N; j++) {
			ands &= Z[i][j];
			ors |= Z[i][j];
		}
		if (A1[i] == 0 && A2[i] != ands) return false;
		if (A1[i] == 1 && A2[i] != ors) return false;
	}

	for (int i = 0; i < N; i++) {
		int ands = 1, ors = 0;
		for (int j = 0; j < N; j++) {
			ands &= Z[j][i];
			ors |= Z[j][i];
		}
		if (B1[i] == 0 && B2[i] != ands) return false;
		if (B1[i] == 1 && B2[i] != ors) return false;
	}
	return true;
}

vector<vector<int>> hanten(vector<vector<int>> Z) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) swap(Z[i][j], Z[j][i]);
	}
	return Z;
}

vector<vector<int>> solve(vector<int> A1, vector<int> B1, vector<int> A2, vector<int> B2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) forced[i][j] = -1;
	}

	vector<int> X, Y;
	for (int i = 0; i < N; i++) {
		if (A1[i] == 0 && A2[i] == 1) {
			X.push_back(i);
			for (int j = 0; j < N; j++) forced[i][j] = 1;
		}
		if (A1[i] == 1 && A2[i] == 0) {
			X.push_back(i);
			for (int j = 0; j < N; j++) forced[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		if (B1[i] == 0 && B2[i] == 1) {
			Y.push_back(i);
			for (int j = 0; j < N; j++) {
				if (forced[j][i] == 0) return vector<vector<int>>{};
				forced[j][i] = 1;
			}
		}
		if (B1[i] == 1 && B2[i] == 0) {
			Y.push_back(i);
			for (int j = 0; j < N; j++) {
				if (forced[j][i] == 1) return vector<vector<int>>{};
				forced[j][i] = 0;
			}
		}
	}

	// 全部自由な場合
	if (X.size() == 0 && Y.size() == 0) {
		vector<vector<int>> S(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) S[i][i] = 1;
		return S;
	}
	
	// X のみ自由な場合
	bool flag = false;
	if (X.size() == 0 && Y.size() != 0) {
		swap(A1, B1);
		swap(A2, B2);
		swap(X, Y);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				swap(forced[i][j], forced[j][i]);
			}
		}
		flag = true;
	}

	// Y のみ自由な場合の特殊ケース
	if (X.size() == N - 1 && Y.size() == 0) {
		int cnt[2] = { 0, 0 };
		for (int i = 0; i < N; i++) { if (forced[i][0] >= 0) cnt[forced[i][0]] = 1; }

		vector<vector<int>> S(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (forced[i][j] != -1) S[i][j] = forced[i][j];
			}
		}

		if (cnt[0] == 1 && cnt[1] == 1) {
			for (int i = 0; i < N; i++) {
				if (forced[i][0] == -1) S[i][i] = 1;
			}
		}
		else {
			vector<int> vec1, vec2;
			int num = 0, val = 0; if (cnt[1] == 1) val = 1;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (forced[i][j] != -1) continue;
					num = i;
					if (B1[j] == (1 ^ val) && B2[j] == (1 ^ val)) { S[i][j] = (1 ^ val); vec1.push_back(j); }
					else { vec2.push_back(j); }
				}
			}
			if (vec1.size() == 0) {
				S[num][0] = (1 ^ val);
				for (int i = 1; i < N; i++) S[num][0] = val;
			}
			else {
				for (int i : vec2) S[num][i] = val;
			}
		}
		if (flag == true) S = hanten(S);
		return S;
	}

	// Y のみ自由な場合
	if (X.size() != 0 && Y.size() == 0) {
		int cnt[2] = { 0, 0 };
		for (int i = 0; i < N; i++) { if (forced[i][0] >= 0) cnt[forced[i][0]] = 1; }

		vector<vector<int>> S(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (forced[i][j] != -1) S[i][j] = forced[i][j];
			}
		}
		if (cnt[1] == 1) {
			for (int i = 0; i < N; i++) {
				if (forced[i][0] == -1) S[i][i] = 1;
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (forced[i][j] != -1) continue;
					if (i == j) S[i][j] = 0;
					else S[i][j] = 1;
				}
			}
		}
		if (flag == true) S = hanten(S);
		return S;
	}
	
	// 全部自由でない場合
	if (X.size() != 0 && Y.size() != 0) {
		vector<vector<int>> S(N, vector<int>(N, 0));
		int col = forced[X[0]][Y[0]];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (forced[i][j] != -1) S[i][j] = forced[i][j];
				else S[i][j] = (1 ^ col);
			}
		}
		return S;
	}

	return vector<vector<int>>{};
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++) cin >> T[i];
	for (int i = 1; i <= N; i++) cin >> U[i];
	for (int i = 1; i <= N; i++) cin >> V[i];

	for (int i = 0; i < 64; i++) {
		vector<int> A1, A2, B1, B2;
		for (int j = 1; j <= N; j++) A1.push_back(S[j]);
		for (int j = 1; j <= N; j++) B1.push_back(T[j]);
		for (int j = 1; j <= N; j++) A2.push_back((U[j] / (1ULL << i)) % 2ULL);
		for (int j = 1; j <= N; j++) B2.push_back((V[j] / (1ULL << i)) % 2ULL);

		if (N <= 3) {
			bool fl = false;
			for (int t = 0; t < (1 << (N * N)); t++) {
				vector<vector<int>> Z(N, vector<int>(N, 0));
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						int idx = j * N + k;
						Z[j][k] = (t / (1 << idx)) % 2;
					}
				}
				if (hantei(Z, A1, B1, A2, B2) == true) {
					for (int j = 1; j <= N; j++) {
						for (int k = 1; k <= N; k++) Answer[j][k] += ((unsigned long long)Z[j - 1][k - 1] << i);
					}
					fl = true;
					break;
				}
			}
			if (fl == false) {
				cout << "-1" << endl;
				return 0;
			}
		}
		else {
			vector<vector<int>> Z = solve(A1, B1, A2, B2);
			if (Z.size() == 0) {
				cout << "-1" << endl;
				return 0;
			}
			if (hantei(Z, A1, B1, A2, B2) == false) {
				cout << "-1" << endl; 
				return 0; 
			}
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) Answer[j][k] += ((unsigned long long)Z[j - 1][k - 1] << i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j >= 2) cout << " ";
			cout << Answer[i][j];
		}
		cout << endl;
	}
	return 0;
}