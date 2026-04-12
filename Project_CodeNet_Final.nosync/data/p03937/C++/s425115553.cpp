#include <iostream>
using namespace std;

void dfs(int a, int b);

bool viz[100][100], disp[100][100];

int main()
{
	int a, b;
	cin >> a >> b;
	char c;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> c;
			if (c == '#')
				disp[i][j] = 1;
		}
	}

	dfs(1, 1);

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (disp[i][j] && !viz[i][j]) {
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}

void dfs(int a, int b)
{
	viz[a][b] = 1;
	if (disp[a + 1][b])
		dfs(a + 1, b);
	else if (disp[a][b + 1])
		dfs(a, b + 1);
}