#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
vector<vector<int> > solve(int N, vector<int> S, vector<int> T, vector<int> U, vector<int> V) {
	// returns the answer for 1-bit, and if it doesn't exist, returns an empty matrix
	vector<vector<int> > ans(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		if (S[i] == 0 && U[i] == 1) {
			for (int j = 0; j < N; ++j) {
				ans[i][j] |= 2;
			}
		}
		if (S[i] == 1 && U[i] == 0) {
			for (int j = 0; j < N; ++j) {
				ans[i][j] |= 1;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (T[i] == 0 && V[i] == 1) {
			for (int j = 0; j < N; ++j) {
				ans[j][i] |= 2;
			}
		}
		if (T[i] == 1 && V[i] == 0) {
			for (int j = 0; j < N; ++j) {
				ans[j][i] |= 1;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			--ans[i][j];
			if (ans[i][j] == 2) {
				return vector<vector<int> >();
			}
		}
	}
	vector<int> reqx, reqy;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 0 && U[i] == 0) {
			bool ok = false;
			for (int j = 0; j < N; ++j) {
				if (ans[i][j] == 0) {
					ok = true;
				}
			}
			if (!ok) {
				reqx.push_back(i);
			}
		}
		if (S[i] == 1 && U[i] == 1) {
			bool ok = false;
			for (int j = 0; j < N; ++j) {
				if (ans[i][j] == 1) {
					ok = true;
				}
			}
			if (!ok) {
				reqx.push_back(i);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (T[i] == 0 && V[i] == 0) {
			bool ok = false;
			for (int j = 0; j < N; ++j) {
				if (ans[j][i] == 0) {
					ok = true;
				}
			}
			if (!ok) {
				reqy.push_back(i);
			}
		}
		if (T[i] == 1 && V[i] == 1) {
			bool ok = false;
			for (int j = 0; j < N; ++j) {
				if (ans[j][i] == 1) {
					ok = true;
				}
			}
			if (!ok) {
				reqy.push_back(i);
			}
		}
	}
	vector<int> remx, remy;
	for (int i = 0; i < N; ++i) {
		bool rems = false;
		for (int j = 0; j < N; ++j) {
			if (ans[i][j] == -1) {
				rems = true;
			}
		}
		if (rems) {
			remx.push_back(i);
		}
	}
	for (int i = 0; i < N; ++i) {
		bool rems = false;
		for (int j = 0; j < N; ++j) {
			if (ans[j][i] == -1) {
				rems = true;
			}
		}
		if (rems) {
			remy.push_back(i);
		}
	}
	if (remx.size() >= 2 && remy.size() >= 2) {
		for (int i = 0; i < remx.size(); ++i) {
			for (int j = 0; j < remy.size(); ++j) {
				ans[remx[i]][remy[j]] = (i + j) % 2;
			}
		}
	}
	else if (reqx.size() == 1 && (reqy.size() != 1 || remx.size() == 1)) {
		for (int i : reqy) {
			if (T[i] == 0 && V[i] == 0) {
				ans[reqx[0]][i] = 0;
			}
			if (T[i] == 1 && V[i] == 1) {
				ans[reqx[0]][i] = 1;
			}
		}
		for (int i = 0; i < N; ++i) {
			if (ans[reqx[0]][i] == -1) {
				if (S[reqx[0]] == 0 && U[reqx[0]] == 0) {
					ans[reqx[0]][i] = 0;
				}
				if (S[reqx[0]] == 1 && U[reqx[0]] == 1) {
					ans[reqx[0]][i] = 1;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (ans[i][j] == -1) {
					ans[i][j] = 0;
				}
			}
		}
	}
	else if (reqy.size() == 1) {
		for (int i : reqx) {
			if (S[i] == 0 && U[i] == 0) {
				ans[i][reqy[0]] = 0;
			}
			if (S[i] == 1 && U[i] == 1) {
				ans[i][reqy[0]] = 1;
			}
		}
		for (int i = 0; i < N; ++i) {
			if(ans[i][reqy[0]] == -1) {
				if (T[reqy[0]] == 0 && V[reqy[0]] == 0) {
					ans[i][reqy[0]] = 0;
				}
				if (T[reqy[0]] == 1 && V[reqy[0]] == 1) {
					ans[i][reqy[0]] = 1;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (ans[i][j] == -1) {
					ans[i][j] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (ans[i][j] == -1) {
					ans[i][j] = 0;
				}
			}
		}
	}
	bool valid = true;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 0) {
			int val = 1;
			for (int j = 0; j < N; ++j) {
				val &= ans[i][j];
			}
			if (val != U[i]) {
				valid = false;
			}
		}
		if (S[i] == 1) {
			int val = 0;
			for (int j = 0; j < N; ++j) {
				val |= ans[i][j];
			}
			if (val != U[i]) {
				valid = false;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (T[i] == 0) {
			int val = 1;
			for (int j = 0; j < N; ++j) {
				val &= ans[j][i];
			}
			if (val != V[i]) {
				valid = false;
			}
		}
		if (T[i] == 1) {
			int val = 0;
			for (int j = 0; j < N; ++j) {
				val |= ans[j][i];
			}
			if (val != V[i]) {
				valid = false;
			}
		}
	}
	if (!valid) {
		return vector<vector<int> >();
	}
	return ans;
}
vector<vector<int> > solve_easy(int N, vector<int> S, vector<int> T, vector<int> U, vector<int> V) {
	for (int i = 0; i < 1 << (N * N); ++i) {
		vector<vector<int> > ans(N, vector<int>(N));
		for (int j = 0; j < N * N; ++j) {
			ans[j / N][j % N] = (i >> j) & 1;
		}
		bool valid = true;
		for (int i = 0; i < N; ++i) {
			if (S[i] == 0) {
				int val = 1;
				for (int j = 0; j < N; ++j) {
					val &= ans[i][j];
				}
				if (val != U[i]) {
					valid = false;
				}
			}
			if (S[i] == 1) {
				int val = 0;
				for (int j = 0; j < N; ++j) {
					val |= ans[i][j];
				}
				if (val != U[i]) {
					valid = false;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (T[i] == 0) {
				int val = 1;
				for (int j = 0; j < N; ++j) {
					val &= ans[j][i];
				}
				if (val != V[i]) {
					valid = false;
				}
			}
			if (T[i] == 1) {
				int val = 0;
				for (int j = 0; j < N; ++j) {
					val |= ans[j][i];
				}
				if (val != V[i]) {
					valid = false;
				}
			}
		}
		if (valid) {
			return ans;
		}
	}
	return vector<vector<int> >();
}
string to_string(vector<int> arr) {
	string res = "[";
	for (int i = 0; i < arr.size(); ++i) {
		if (i) res += ", ";
		res += to_string(arr[i]);
	}
	res += "]";
	return res;
}
string to_string(vector<vector<int> > mat) {
	string res = "[";
	for (int i = 0; i < mat.size(); ++i) {
		if (i) res += ", ";
		res += to_string(mat[i]);
	}
	res += "]";
	return res;
}
void random_gen() {
	for (int N = 1; N <= 4; ++N) {
		int num_cases = 0;
		for (int i = 0; i < 1 << (4 * N); ++i) {
			++num_cases;
			vector<int> S(N), T(N), U(N), V(N);
			for (int j = 0; j < N; ++j) {
				S[j] = (i >> j) & 1;
				T[j] = (i >> (j + N)) % N;
				U[j] = (i >> (j + 2 * N)) % N;
				V[j] = (i >> (j + 3 * N)) % N;
			}
			vector<vector<int> > res1 = solve(N, S, T, U, V);
			vector<vector<int> > res2 = solve_easy(N, S, T, U, V);
			if (res1.empty() != res2.empty()) {
				cout << "N = " << N << " / Case #" << num_cases << ":" << endl;
				cout << "S = " << to_string(S) << endl;
				cout << "T = " << to_string(T) << endl;
				cout << "U = " << to_string(U) << endl;
				cout << "V = " << to_string(V) << endl;
				cout << "Returns: " << to_string(res1) << endl;
				cout << "Answer: " << to_string(res2) << endl;
				cout << endl;
			}
		}
		cout << "N = " << N << " Completed! (" << num_cases << " Cases)" << endl;
	}
}
int main() {
	// random_gen();
	int N;
	cin >> N;
	vector<int> S(N), T(N);
	vector<unsigned long long> U(N), V(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> U[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> V[i];
	}
	bool found = true;
	vector<vector<unsigned long long> > ans(N, vector<unsigned long long>(N));
	for (int i = 0; i < 64; ++i) {
		vector<int> u(N), v(N);
		for (int j = 0; j < N; ++j) {
			u[j] = (U[j] >> i) & 1;
			v[j] = (V[j] >> i) & 1;
		}
		vector<vector<int> > arr = solve(N, S, T, u, v);
		if (arr == vector<vector<int> >()) {
			found = false;
			break;
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				ans[j][k] |= (unsigned long long)(arr[j][k]) << i;
			}
		}
	}
	if (found) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (j) cout << ' ';
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}