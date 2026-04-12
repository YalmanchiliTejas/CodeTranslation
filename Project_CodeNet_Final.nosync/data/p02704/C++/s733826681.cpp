#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

ll A[502][502];
ll S[502], T[502], U[502], V[502];
bool st[502][502];
bool R[502], C[502];
bool Rand[502], Ror[502], Cand[502], Cor[502];
int N;

int solve(ll bit) {
	for (int i = 0;i < N;i++) {
		if (U[i] & ((ll)1 << bit))R[i] = 1;
		else R[i] = 0;
		if (V[i] & ((ll)1LL << bit))C[i] = 1;
		else C[i] = 0;
	}
	int rand1 = 0, ror0 = 0, cand1 = 0, cor0 = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			st[i][j] = 0;
		}
	}
	for (int i = 0;i < N;i++) {
		if (!S[i] && R[i]) {
			rand1++;
		}
		if (S[i] && !R[i]) {
			ror0++;
		}
		if (!T[i] && C[i]) {
			cand1++;
		}
		if (T[i] && !C[i]) {
			cor0++;
		}
		Rand[i] = 1;
		Ror[i] = 0;
		Cand[i] = 1;
		Cor[i] = 0;
	}
	if (rand1 && cor0) {
		return 1;
	}
	if (ror0 && cand1) {
		return 1;
	}

	if (rand1 + ror0 == N || cand1 + cor0 == N) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (!S[i] && R[i]) {
					st[i][j] = 1;
				}
				else if (S[i] && !R[i]) {
					st[i][j] = 0;
				}
				else if (!T[j] && C[j]) {
					st[i][j] = 1;
				}
				else if (T[j] && !C[j]) {
					st[i][j] = 0;
				}
				Rand[i] = Rand[i] & st[i][j];
				Cand[j] = Cand[j] & st[i][j];
				Ror[i] = Ror[i] | st[i][j];
				Cor[j] = Cor[j] | st[i][j];
			}
		}
		for (int i = 0;i < N;i++) {
			if (S[i]) {
				if (Ror[i] != R[i])return 3;
			}
			else {
				if (Rand[i] != R[i])return 3;
			}
			if (T[i]) {
				if (Cor[i] != C[i])return 3;
			}
			else {
				if (Cand[i] != C[i])return 3;
			}
		}
	}
	else if (rand1 + ror0 == N - 1 || cand1 + cor0 == N - 1) {
		if (rand1 + ror0 != N - 1) {
			for (int i = 0;i < N;i++) {
				swap(R[i], C[i]);
				swap(S[i], T[i]);
			}
		}
		int sj = -1;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (!S[i] && R[i]) {
					st[i][j] = 1;
					Rand[i] = Rand[i] & st[i][j];
					Cand[j] = Cand[j] & st[i][j];
					Ror[i] = Ror[i] | st[i][j];
					Cor[j] = Cor[j] | st[i][j];
				}
				else if (S[i] && !R[i]) {
					st[i][j] = 0;
					Rand[i] = Rand[i] & st[i][j];
					Cand[j] = Cand[j] & st[i][j];
					Ror[i] = Ror[i] | st[i][j];
					Cor[j] = Cor[j] | st[i][j];
				}
				else {
					sj = i;
				}
			}
		}
		queue<int> Q;
		for (int j = 0;j < N;j++) {
			if (T[j]) {
				if (Cor[j] && !C[j]) {
					return 2;
				}
				else if (!Cor[j] && C[j]) {
					st[sj][j] = 1;
					Rand[sj] = Rand[sj] & 1;
					Ror[sj] = Ror[sj] | 1;
				}
				else if (!Cor[j] && !C[j]) {
					st[sj][j] = 0;
					Rand[sj] = Rand[sj] & 0;
					Ror[sj] = Ror[sj] | 0;
				}
				else {
					Q.push(j);
				}
			}
			else {
				if (Cand[j] && !C[j]) {
					st[sj][j] = 0;
					Rand[sj] = Rand[sj] & 0;
					Ror[sj] = Ror[sj] | 0;
				}
				else if (!Cand[j] && C[j]) {
					return 2;
				}
				else if (Cand[j] && C[j]) {
					st[sj][j] = 1;
					Rand[sj] = Rand[sj] & 1;
					Ror[sj] = Ror[sj] | 1;
				}
				else {
					Q.push(j);
				}
			}
		}
		if (S[sj]) {
			if (Ror[sj] && !R[sj]) {
				return 1;
			}
			else if (!Ror[sj] && R[sj]) {
				if (Q.empty())return 1;
				else {
					while (!Q.empty()) {
						st[sj][Q.front()] = 1;
						Q.pop();
					}
				}
			}
			else {
				while (!Q.empty()) {
					st[sj][Q.front()] = 0;
					Q.pop();
				}
			}
		}
		else {
			if (Rand[sj] && !R[sj]) {
				if (Q.empty())return 1;
				else {
					while (!Q.empty()) {
						st[sj][Q.front()] = 0;
						Q.pop();
					}
				}
			}
			else if (!Rand[sj] && R[sj]) {
				return 1;
			}
			else {
				while (!Q.empty()) {
					st[sj][Q.front()] = 1;
					Q.pop();
				}
			}
		}
		
		if (rand1 + ror0 != N - 1) {
			for (int i = 0;i < N;i++) {
				swap(R[i], C[i]);
				swap(S[i], T[i]);
			}
			for (int i = 0;i < N;i++) {
				for (int j = i;j < N;j++) {
					swap(st[i][j], st[j][i]);
				}
			}
		}
	}
	else {
		int cr = -1, cc;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (!S[i] && R[i]) {
					st[i][j] = 1;
				}
				else if (S[i] && !R[i]) {
					st[i][j] = 0;
				}
				else if (!T[j] && C[j]) {
					st[i][j] = 1;
				}
				else if (T[j] && !C[j]) {
					st[i][j] = 0;
				}
				else {
					if (cr < 0) {
						st[i][j] = 1;
						cr = i, cc = j;
					}
					else {
						if (i == cr)st[i][j] = 0;
						else if (j == cc)st[i][j] = 0;
						else st[i][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (st[i][j]) {
				A[i][j] += (1LL << bit);
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			A[i][j] = st[i][j] = 0;
		}
	}
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> S[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> T[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> U[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> V[i];
	}

	if (N == 1) {
		if (U[0] == V[0])cout << U[0] << endl;
		else cout << -1 << endl;
		return 0;
	}

	int x;
	for (int i = 0;i < 64;i++) {
		x = solve(i);
		if (x == 3)exit(-1);
		if (x == 1) {
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}