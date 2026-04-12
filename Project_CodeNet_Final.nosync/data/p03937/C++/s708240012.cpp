#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

int H, W;
bool maze[8][8];

void input() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char tmp; cin >> tmp;
			if (tmp == '#') maze[i][j] = true;
		}
	}
}

void dfs(int row, int col) {
	maze[row][col] = false;
	if (row + 1 < H && maze[row + 1][col]) dfs(row + 1, col);
	else if (col + 1 < W && maze[row][col + 1]) dfs(row, col + 1);
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	dfs(0, 0);
	bool flag = true;
	for (int i = 0; i < H && flag; i++) {
		for (int j = 0; j < W && flag; j++) {
			if (maze[i][j]) flag = false;
		}
	}

	if(flag) cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}