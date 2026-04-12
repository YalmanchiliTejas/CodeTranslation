#include <bits/stdc++.h>
using namespace std;

const int N = 110;

char str[N][N];
int R[N], C[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];
	
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) cnt += str[i][j] == '#';
		if (!cnt) R[i] = 1;
	}
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += str[i][j] == '#';
		if (!cnt) C[j] = 1;
	}
	
	for (int i = 0; i < n; i++) if (!R[i]) {
		for (int j = 0; j < m; j++) if (!C[j]) cout << str[i][j];
		cout << "\n";
	}
	
	return 0;
}