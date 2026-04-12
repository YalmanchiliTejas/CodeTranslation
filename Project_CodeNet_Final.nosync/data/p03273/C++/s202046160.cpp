#include<iostream>
#include<vector>
using namespace std;
char a[110][110];
bool b[110], c[110];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		bool f = false;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')f = true;
		}
		if (!f)b[i] = true;
	}
	for (int i = 0; i < m; i++) {
		bool f = false;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == '#')f = true;
		}
		if (!f)c[i] = true;
	}
	for (int i = 0; i < n; i++) {
		if (b[i])continue;
		for (int j = 0; j < m; j++) {
			if (c[j])continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}