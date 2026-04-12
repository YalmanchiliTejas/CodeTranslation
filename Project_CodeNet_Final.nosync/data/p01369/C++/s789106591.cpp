#include <bits/stdc++.h>

using namespace std;

string S;

char rights[11] = {'y','u','i','o','p','h','j','k','l','n','m'};

bool isright(char c) {
	for (int i = 0; i < 11; i++) if (rights[i] == c) return true;
	return false;
}

void solve() {
	int cnt = 0;
	int n = (int)S.size();	
	bool prev = 0;
	
	for (int i = 0; i < n; i++) {
		bool cur = isright(S[i]);
		if (i != 0 && cur != prev) cnt++;
		prev = cur;
	}
	
	cout << cnt << endl;
}

int main() {
	while (1) {
		cin >> S; if (S[0] == '#') break;
		solve();
	}
	
	return 0;
}