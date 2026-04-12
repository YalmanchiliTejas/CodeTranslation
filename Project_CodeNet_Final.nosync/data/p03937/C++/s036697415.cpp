#include <iostream>
using namespace std;

char ar[10][10];
int cnt, h, w;

bool f(int i, int j, int cur)
{
	if (i >= h or j >= w)
		return false;
	if (ar[i][j] == '.')
		return false;
	if (i == h - 1 and j == w - 1 and cur == cnt)
		return true;
	if (i == h - 1 and j == w - 1)
		return false;
	return f(i + 1, j, cur + 1) or f(i, j + 1, cur + 1);
}

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			cin >> ar[i][j];
			if (ar[i][j] == '#')
				++cnt;
		}

	cout << (f(0, 0, 1) ? "Possible" : "Impossible");

	return 0;
}
