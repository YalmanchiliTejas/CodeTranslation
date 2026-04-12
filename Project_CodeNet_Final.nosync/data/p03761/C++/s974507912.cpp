#define _USE_NATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <random>
#include <tuple>


using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
#define EPS 1e-9
const int INF = 1050000000;
const long long LINF = 1LL << 60;
const ll MOD = 1e9 + 7;
const int MINF = -1050000000;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main() {
	
	int n;
	cin >> n;
	
	map<char, int> ans,t;
	string s;
	cin >> s;
	for (auto st : s) ans[st]++;
	
	for (int i = 0; i < n - 1; ++i) {
		t.clear();
		cin >> s;
		for (auto st : s) t[st]++;
		for (char j = 'a'; j <= 'z'; ++j) ans[j] = min(ans[j], t[j]);
	}

	for (auto a : ans) if (a.second > 0) rep(i, a.second) cout << a.first;
	cout << endl;
	return 0;
}
