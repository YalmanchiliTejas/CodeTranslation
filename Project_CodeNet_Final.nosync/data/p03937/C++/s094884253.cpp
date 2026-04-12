#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
	int h, w;
	cin >> h >> w;
	vec<string> a(h);
	rep(i, h) cin >> a[i];

	int flag = 1;
	rep(i, h - 1) rep(j, w - 1) {
		if (a[i][j] == '#') {
			if (a[i][j + 1] == a[i + 1][j]) flag = 0;
		} else {
			if (a[i][j + 1] == '#' && a[i + 1][j] == '#') flag = 0;
			else if (a[i][j + 1] == '.' && a[i + 1][j] == '.' && a[i + 1][j + 1] == '#') flag = 0;
		}
	}
	if (flag) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}