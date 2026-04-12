#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>
#include <queue>
#include <set>
#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1(j,n) for(int j=0;j<(int)n;++j)
#define REPD(i,n) for(int i=n;i>=0;--i)
#define REPD1(j,n) for(int j=n;j=>0;--j)
#define REPS(i,n) for(int i=1;i<=(int)n;++i)
#define REPS1(j,n) for(int j=1;j<=(int)n;++j)
#define rep(i,a,n) for(int i=a;i<=(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;
const ll INF=1e9+7;

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> table(h, vector<char>(w));
	vector<vector<char>> ans;
	ans.emplace_back();
	REP(i, h)REP1(j, w)cin >> table[i][j];
	REP(i, h) {
		REP1(j, w) {
			if (table[i][j] == '#') {
				ans[i].push_back(table[i][j]);
			}
			else {
				bool can1, can2;can1 = can2 = false;
				for (int k = 0;k < h;k++) {
					if (table[k][j] == '#') {
						can1 = true;
						break;
					}
				}
				for (int k = 0;k < w;++k) {
					if (table[i][k] == '#') {
						can2 = true;
						break;
					}
				}
				if (can1 && can2)ans[i].push_back(table[i][j]);
			}
		}
		ans.emplace_back();
	}
	REP(i, ans.size()) {
		if (ans[i].size() == 0)continue;
		REP(j, ans[i].size()) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}