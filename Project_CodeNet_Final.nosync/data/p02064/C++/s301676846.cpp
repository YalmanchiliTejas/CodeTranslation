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
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
/*
pair<long long, long long> and_expr(State &a);
pair<long long, long long> term(State &a);
pair<long long, long long> or_expr(State &a) {
	pair<long long, long long> ans = and_expr(a);
	while (*a != '!') {
		if (*a == '|') {
			a++;
			pair<long long, long long> now = or_expr(a);
			//to be 1
			//both 1 or either 1
			ans.second = min(ans.second,now.second);
			//to be 0
		//both 0
			ans.first = ans.first + now.first;
		}
		else {
			break;
		}
	}
	return ans;
}
pair<long long, long long> and_expr(State &a) {
	pair<long long, long long> ans = term(a);
	while (*a != '!') {
		if (*a == '&') {
			a++;
			pair<long long, long long> now = and_expr(a);
			//to be 0
			//either should be 0
			long long geko = ans.first;
			geko = min(geko, now.first);
			//to be 1
			//both should be 1
			ans.second = ans.second+now.second;
			ans.first = geko;
		}
		else {
			break;
		}
	}
	return ans;
}
pair<long long, long long> term(State &a) {
	if (*a == '(') {
		a++;
		pair<int,int> now = or_expr(a);
		a++;
		return now;
	}
	else if (*a == '?') {
		a++;
		return make_pair(1, 1);
	}
}
int main() {
	string s;
	cin >> s;
	s.push_back('!');
	State hoge = s.begin();
	pair<int, int> ans = or_expr(hoge);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
*/
vector<tuple<int,int, int>> now_data; //s -> vertex_num dist,vertex_num -> t dist, vertex_num
long long query(long long a,long long b) {
	cout << "? " << a << " " << b << endl;
	cout.flush();
	long long c;
	cin >> c;
	return c;
}
int main() {
	int n, s, t;
	cin >> n >> s >> t;
	long long dist = query(s, t);
	for (int i = 1; i <= n; ++i) {
		if (s == i || t == i) continue;
		long long a = query(s, i);
		long long b = query(i, t);
		if (a + b == dist) {
			now_data.push_back(make_tuple(a, b, i));
		}
	}
	if (now_data.size() == 0) {
		cout << "! " << s << " " << t << endl;
		cout.flush();
		return 0;
	}
	sort(now_data.begin(), now_data.end());
	vector<int> ans;
	ans.push_back(s);
	int back = 0;
	ans.push_back(get<2>(now_data[0]));
	for (int i = 1; i < now_data.size(); ++i) {
		long long geko = query(get<2>(now_data[i]), get<2>(now_data[back]));
		if (get<0>(now_data[i]) == get<0>(now_data[back]) + geko) {
			ans.push_back(get<2>(now_data[i]));
			back = i;
		}
	}
	ans.push_back(t);
	cout << "!";
	REP(i, ans.size()) {
		cout << " " << ans[i];
	}
	cout << endl;
	cout.flush();
}
