#define  _CRT_SECURE_NO_WARNINGS
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
#define LONG_INF 800000000000000000
vector<int> vertexs[10];
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	int ans = 0;
	queue<pair<int, int>> wow;
	wow.push(make_pair(1, 1));
	while (wow.empty() == false) {
		pair<int, int> hoge = wow.front();
		wow.pop();
		if (hoge.second == (1 << n) - 1) {
			ans++;
			goto ooo;
		}
		for (int j = 0;j < vertexs[hoge.first].size();++j) {
			if (((1 << (vertexs[hoge.first][j]-1))&hoge.second) == 0) {
				wow.push(make_pair(vertexs[hoge.first][j], (1 << (vertexs[hoge.first][j]-1)) + hoge.second));
			}
		}
	ooo:;
	}
	cout << ans << endl;
	return 0;
}