#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


int n;
string s;
int p[2 << 18];

int win[20][2 << 18];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> s;
	rep(i, 1 << n)cin >> p[i];
	rep(i, 1 << n)p[i + (1 << n)] = p[i];

	rep(i, 2 << n)win[0][i] = p[i];

	rep(i, n) {
		rep(j, 2 << n) {
			if (j + (1 << i) >= (2 << n))break;
			int x = win[i][j];
			int y = win[i][j + (1 << i)];

			win[i + 1][j] = s[abs(x - y) - 1] == '0' ? min(x, y) : max(x, y);
		}
	}
	rep(i, 1<<n) {
		cout << win[n][i] << '\n';
	}


	return 0;
}
