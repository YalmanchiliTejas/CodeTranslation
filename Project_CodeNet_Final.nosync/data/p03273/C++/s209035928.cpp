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
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

bool grid[109][109];
bool need1[109];
bool need2[109];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char tmp; cin >> tmp;
			if (tmp == '.') grid[i][j] = true;
		}
	}

	for(int i = 0; i < H; i++) {
		bool need = false;
		for (int j = 0; j < W && !need; j++) {
			if (!grid[i][j]) need = true;
		}
		if (need) need1[i] = true;
	}
	for (int j = 0; j < W; j++) {
		bool need = false;
		for (int i = 0; i < H && !need; i++) {
			if (!grid[i][j]) need = true;
		}
		if (need) need2[j] = true;
	}

	for (int i = 0; i < H; i++) {
		if (need1[i]) {
			for (int j = 0; j < W; j++) {
				if (need2[j]) {
					if (grid[i][j]) cout << ".";
					else cout << "#";
				}
			}
			cout << endl;
		}
	}

	return 0;
}