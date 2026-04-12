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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
vector<pair<long long, long long>> vertexs[200000];
long long already[200000] = {};
int main() {
#define int long long
	int n;
	cin >> n;
	vector<tuple<long long, long long, long long>> wow, aa;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		wow.push_back(make_tuple(a, b, i));
		aa.push_back(make_tuple(b, a, i));
	}
	sort(wow.begin(), wow.end());
	long long ans = 0;
	for (int i = 0;i < n - 1;++i) {
		vertexs[get<2>(wow[i])].push_back(make_pair(get<2>(wow[i + 1]), get<0>(wow[i + 1]) - get<0>(wow[i])));
		vertexs[get<2>(wow[i + 1])].push_back(make_pair(get<2>(wow[i]), get<0>(wow[i + 1]) - get<0>(wow[i])));
	}
	sort(aa.begin(), aa.end());
	for (int i = 0;i < n - 1;++i) {
		vertexs[get<2>(aa[i])].push_back(make_pair(get<2>(aa[i + 1]), get<0>(aa[i + 1]) - get<0>(aa[i])));
		vertexs[get<2>(aa[i + 1])].push_back(make_pair(get<2>(aa[i]), get<0>(aa[i + 1]) - get<0>(aa[i])));
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp;
	tmp.push(make_pair(0, 0));
	while (tmp.empty() == false) {
		pair<int, int> now = tmp.top();
		tmp.pop();
		if (already[now.second] == false) {
			ans += now.first;
			already[now.second] = true;
			for (int i = 0;i < vertexs[now.second].size();++i) {
				if (already[vertexs[now.second][i].first] == false) {
					tmp.push(make_pair(vertexs[now.second][i].second, vertexs[now.second][i].first));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}