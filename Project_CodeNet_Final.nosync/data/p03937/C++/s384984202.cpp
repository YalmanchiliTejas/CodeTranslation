#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	string arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == '#')
				cnt++;
	if (cnt != m + n - 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	int a = 0, b = 0;
	while (a < n - 1 && b < m - 1) {
		if (b < m - 1) {
			if (arr[a][b + 1] == '#')
				b++;
			else if (a < n - 1) {
				if (arr[a + 1][b] != '#') {
					cout << "Impossible" << endl;
					return 0;
					break;
				}
				else
					a++;
			}
			else {
				cout << "Impossible" << endl;
				return 0;
				break;
			}
		}
		else if (arr[a + 1][b] != '#') {
			cout << "Impossible" << endl;
			return 0;
		}
		else
			a++;
	}
	cout << "Possible" << endl;
	return 0;
}