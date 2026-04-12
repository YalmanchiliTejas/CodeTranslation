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
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	string s[8];
	int y=0, x=0;
	cin >> h >> w;
	rep(i,h) {
		cin >> s[i];
	}
	int v[8][8] = {};

	while (1) {
		v[y][x] = 1;
		if (y+1<h&&s[y+1][x]=='#') {
			y++;
		}
		else if (x+1<w&&s[y][x+1]=='#') {
			x++;
		}
		else break;
	}
	bool ok = true;
	rep(i,h) rep(j,w){
		if (v[i][j] != (s[i][j] == '#'))ok = false;
	}
	cout << (ok ? "Possible" : "Impossible") << endl;


	return 0;
}