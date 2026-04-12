#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string s;
char ans[100001];

void sim() {
	for(int i = 1; i <= N; i++) {
		if (s[i] == 'o') {
			if (ans[i] == 'S') {
				if (ans[i - 1] == 'S') ans[i + 1] = 'S';
				else ans[i + 1] = 'W';
			} else {
				// W
				if (ans[i - 1] == 'S') ans[i + 1] = 'W';
				else ans[i + 1] = 'S';
			}
		} else {
			// x
			if (ans[i] == 'S') {
				if (ans[i - 1] == 'S') ans[i + 1] = 'W';
				else ans[i + 1] = 'S';
			} else {
				// W
				if (ans[i - 1] == 'S') ans[i + 1] = 'S';
				else ans[i + 1] = 'W';
			}
		}

	}
}

bool s_check() {
	if (s[0] == 'o') {
		if (ans[N-1] == ans[1] && ans[0] == ans[N]) {
			for(int i = 0; i < N; i++) cout << ans[i];
			cout << endl;
			return true;
		}
	} else {
		if (ans[N-1] != ans[1] && ans[0] == ans[N]) {
			for(int i = 0; i < N; i++) cout << ans[i];
			cout << endl;
			return true;
		}
	}
	return false;
}

bool w_check () {
	if (s[0] == 'o') {
		if (ans[N-1] != ans[1] && ans[0] == ans[N]) {
			for(int i = 0; i < N; i++) cout << ans[i];
			cout << endl;
			return true;
		}
	} else {
		if (ans[N-1] == ans[1] && ans[0] == ans[N]) {
			for(int i = 0; i < N; i++) cout << ans[i];
			cout << endl;
			return true;
		}
	}

	return false;
}

int main () {
	cin >> N >> s;
	
	// Sheep loop
	ans[0] = 'S';
	ans[1] = 'S';
	sim();
	if (s_check()) return 0;

	ans[0] = 'S';
	ans[1] = 'W';
	sim();
	if (s_check()) return 0;

	// Wolf loop
	ans[0] = 'W';
	ans[1] = 'S';
	sim();
	if (w_check()) return 0;

	ans[0] = 'W';
	ans[1] = 'W';
	sim();
	if (w_check()) return 0;
	
	cout << -1 << endl;

	return 0;
}