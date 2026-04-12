#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

char A[8][8];

int main()
{
	int H, W, x = 0, y = 0;
	bool ans = true;

	cin >> H >> W;
	rep(i, H) rep(j, W) cin >> A[i][j];

	A[0][0] = '*';
	while (!(x == H - 1 && y == W - 1)) {
		if (x != H - 1 && A[x + 1][y] == '#') x++;
		else if (y != W - 1 && A[x][y + 1] == '#') y++;
		else break;
		A[x][y] = '*';
	}

	rep(i, H) rep(j, W) if (A[i][j] == '#') ans = false;

	cout << (ans ? "Possible" : "Impossible") << endl;

	return 0;
}
