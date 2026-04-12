#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	char arr[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		bool flag = 0;
		for (int j = 0; j < m && !flag; j++) {
			if (arr[i][j] == '#') {
				flag = 1;
			}
		}
		for (int j = 0; j < m && !flag; j++) {
			arr[i][j] = '1';
		}
	}

	for (int i = 0; i < m; i++) {
		bool flag = 0;
		for (int j = 0; j < n && !flag; j++) {
			if (arr[j][i] == '#')
				flag = 1;
		}
		for (int j = 0; j < n && !flag; j++) {
			arr[j][i] = '1';
		}
	}


	for (int i = 0; i < n; i++) {
		bool flag = 0;
		for (int j = 0; j < m; j++)
			if (arr[i][j] != '1') {
				flag = 1;
				cout << arr[i][j];
			}

		if (flag)
			cout << endl;
	}

}
