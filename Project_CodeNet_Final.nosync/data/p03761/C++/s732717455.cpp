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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n = 0;
	cin >> n;
	vector<string> hoge;
	for(int i = 0;i < n;++i) {
		string s;
		cin >> s;
		hoge.push_back(s);
	}
	int syugou[1000] = {};
	for (int i = 0;i < hoge[0].length();++i) {
		syugou[hoge[0][i] - 'a']++;
	}
	for (int i = 1;i < hoge.size();++i) {
		int pre_syugou[1000] = {};
		for (int q = 0;q < hoge[i].length();++q) {
			pre_syugou[hoge[i][q] - 'a']++;
		}
		for (int i = 0;i < 26;++i) {
			syugou[i] = min(syugou[i], pre_syugou[i]);
		}
	}
	for (int i = 0;i < 26;++i) {
		for (int q = 0;q < syugou[i];++q) {
			cout << (char)(i + 'a');
		}
	}
	cout << endl;
	return 0;
}