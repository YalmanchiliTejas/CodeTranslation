#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
const long double pi = 3.14159265358979323846264338327950288;
bool a[8][8];
bool l = 0;
char b[8][8];
int h, w, sum = 0;
void solve(int i, int j,int s) {
	if (i == h - 1 && j == w - 1) {
		if (sum == s)
			l = 1;
		return;
	}
	if (i + 1 < h&&b[i + 1][j] == '#')
		solve(i + 1, j, s + 1);
	if (j + 1 < w&&b[i][j + 1] == '#')
		solve(i, j + 1, s + 1);
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b[i][j];
			if (b[i][j] == '#')
				sum++;
		}
	}
	solve(0, 0, 1);
	if (l)
		cout << "Possible\n";
	else
		cout << "Impossible\n";
	cin >> h;
}