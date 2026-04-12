#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
int test[213456];
char maze[213][213];
signed main() {
	int n, m, ans = 0; cin >> n >> m;
	char a;
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= m; i++) {
			cin >> a; maze[h][i] = a;
		}
	}
	for (int h = 1; h <= n; h++) {
		int count = 0;
		for (int i = 1; i <= m; i++) {
			if (maze[h][i] == '.') { count++; }
		}
		if (count == m) {
			for (int j = h + 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					maze[j - 1][k] = maze[j][k];
				}
			}
			n--; h--;
		}
	}
	for (int h = 1; h <= m; h++) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (maze[i][h] == '.') { count++; }
		}
		if (count == n) {
			for (int j = 1; j <= n; j++) {
				for (int k = h + 1; k <= m; k++) {
					maze[j][k - 1] = maze[j][k];
				}
			}
			m--; h--;
		}
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= m; i++) {
			cout << maze[h][i];
		}
		cout << endl;
	}
}