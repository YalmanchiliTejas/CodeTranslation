#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int h, w;
	cin >> h >> w;
	int hoge[100][100] = {};
	REP(i, h) {
		string s;
		cin >> s;
		REP(q, w) {
			if (s[q] == '#') {
				hoge[i][q] = 1;
			}
		}
	}
	pair<int, int> basho = make_pair(0, 0);
	if (hoge[0][0] != 0) {
		hoge[0][0] = 0;
		while (true) {
			if (basho.first != h - 1 && hoge[basho.first + 1][basho.second] == 1) {
				hoge[basho.first + 1][basho.second] = 0;
				basho.first++;
			}
			else if (basho.second != w - 1 && hoge[basho.first][basho.second + 1] == 1) {
				hoge[basho.first][basho.second + 1] = 0;
				basho.second++;
			}
			else break;
		}
	}
	for (int i = 0;i < h;++i) {
		for (int q = 0;q < w;++q) {
			if (hoge[i][q] != 0) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}