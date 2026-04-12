//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 1000 + 17;

int h, w, x = 1, y = 1;
char a[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> h >> w;
	memset(a, '.', sizeof(a));
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> a[i][j];
	a[x][y] = '.';
	while (x != h || y != w) {
		if (a[x][y + 1] == '#') {
			a[x][y + 1] = '.';
			y++;
			continue;
		}
		if (a[x + 1][y] == '#') {
			a[x + 1][y] = '.';
			x++;
			continue;
		}
		cout << "Impossible";
		return 0;
	}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (a[i][j] == '#') {
				cout << "Impossible";
				return 0;
			}
	cout << "Possible";
	return 0;
}
