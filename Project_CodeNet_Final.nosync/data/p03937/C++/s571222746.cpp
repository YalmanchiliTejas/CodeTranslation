#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

signed main() {
	int H, W;
	cin >> H >> W;

	vector<string> board(H);
	rep(i, H) cin >> board[i];

	int x = 0, y = 0;
	bool ok = true;
	while (x != W - 1 || y != H - 1) {
		board[y][x] = '.';
		if (x < W - 1 && board[y][x + 1] == '#') x++;
		else if (y < H - 1 && board[y + 1][x] == '#') y++;
		else {
			ok = false;
			break;
		}
	}
	board[y][x] = '.';

	rep(y, H) rep(x, W) {
		if (board[y][x] == '#') ok = false;
	}

	cout << (ok ? "Possible" : "Impossible") << endl;
}
