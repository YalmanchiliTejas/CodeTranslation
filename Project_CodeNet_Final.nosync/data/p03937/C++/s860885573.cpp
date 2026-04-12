#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#include<complex>
#define EPS 1e-10
using namespace std;
typedef long long llong;

int h, w;
int cnt1 = 0,cnt2=0;
vector<string>v;
bool dfs1(int x, int y) {

	if (x == h - 1 && y == w - 1)return true;

	if (y == w)return false;
	if (x == h)return false;
	bool f, g;
	if (v[x][y] == '#') {
		cnt1++;
		//cout << "x = " << x << "  y = " << y << "  cnt = " << cnt << endl;
		return dfs1(x + 1, y) | dfs1(x, y + 1);



	}

	else return false;


}

bool dfs2(int x, int y) {

	if (x == 0 && y == 0)return true;

	if (y == -1)return false;
	if (x == -1)return false;
	
	if (v[x][y] == '#') {
		cnt2++;
		//cout << "x = " << x << "  y = " << y << "  cnt = " << cnt << endl;
		return dfs2(x - 1, y) | dfs2(x, y - 1);



	}

	else return false;


}

int main() {
	cin >> h >> w;
	int value = h + w - 1-1;
	v = vector<string>(h);
	for (int i = 0; i < h; i++) {
		cin >> v[i];
	}
	bool f, g;
	int x = 0, y = 0;
	f = dfs1(x, y);
	x = h - 1; y = w - 1;
	g = dfs2(x, y);

	if (f&&g&&value == cnt1&&value == cnt2) {

		cout << "Possible" << endl;

	}
	else cout << "Impossible" << endl;

//	cout << cnt << endl;

	return 0;
}