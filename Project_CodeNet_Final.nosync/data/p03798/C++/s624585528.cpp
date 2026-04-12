#include <iostream>
#include <vector>

using namespace std;

enum animal { unk = 0, sheep, wolf };

bool check(vector<animal> &as, string S) {
	int n = as.size();
	for (int i = 0; i < n; i++) {
		if ((as[i] == sheep && S[i] == 'o') || (as[i] == wolf && S[i] == 'x')) {
			if (as[(i-1+n) % n] == unk) {
				as[(i-1+n) % n] = as[(i+1) % n];
			} else if (as[(i+1) % n] == unk) {
				as[(i+1) % n] = as[(i-1+n) % n];
			} else if (as[(i-1+n) % n] != as[(i+1) % n]) {
				return false;
			}
		} else if ((as[i] == sheep && S[i] == 'x') || (as[i] == wolf && S[i] == 'o')) {
			if (as[(i-1+n) % n] == unk) {
				as[(i-1+n) % n] = (as[(i+1) % n] == sheep) ? wolf : sheep;
			} else if (as[(i+1) % n] == unk) {
				as[(i+1) % n] = (as[(i-1+n) % n] == sheep) ? wolf : sheep;
			} else if (as[(i-1+n) % n] == as[(i+1) % n]) {
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char *argv[]) {
	int N;
	cin >> N;

	string S;
	cin >> S;

	vector<animal> ans(N);


	bool solved;
	for (int i = 0; i < N; i++) ans[i] = unk;
	ans[0] = sheep;
	ans[1] = sheep;
	solved = check(ans, S);
	if (solved) {
		for (int i = 0; i < N; i++) {
			if (ans[i] == sheep) printf("S");
			if (ans[i] == wolf) printf("W");
		}
		cout << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) ans[i] = unk;
	ans[0] = sheep;
	ans[1] = wolf;
	solved = check(ans, S);
	if (solved) {
		for (int i = 0; i < N; i++) {
			if (ans[i] == sheep) printf("S");
			if (ans[i] == wolf) printf("W");
		}
		cout << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) ans[i] = unk;
	ans[0] = wolf;
	ans[1] = sheep;
	solved = check(ans, S);
	if (solved) {
		for (int i = 0; i < N; i++) {
			if (ans[i] == sheep) printf("S");
			if (ans[i] == wolf) printf("W");
		}
		cout << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) ans[i] = unk;
	ans[0] = wolf;
	ans[1] = wolf;
	solved = check(ans, S);
	if (solved) {
		for (int i = 0; i < N; i++) {
			if (ans[i] == sheep) printf("S");
			if (ans[i] == wolf) printf("W");
		}
		cout << endl;
		return 0;
	}

	cout << -1 << endl;
	return 0;
}