#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int myMin(vi& v) {
	sort(all(v));
	return v.at(0);
}

int main() {
	int n; cin >> n;
	map<char, vi> mp;
	rep(i, n) {
		string s; cin >> s;
		int len = s.size();
		rep(k, 26) {
			mp['a' + k].push_back(0);
		}
		rep(j, len) {
			mp[s.at(j)].at(i)++;
		}
	}
	rep(i, 26) {
		int m = myMin(mp[(char)('a' + i)]);
		rep(j, m) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;
	return 0;
}
