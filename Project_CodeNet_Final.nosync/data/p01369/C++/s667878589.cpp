#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <bitset>
#include <random>
#include <functional>
#include <sstream>
#include <iomanip>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef long long LL;

string r = "qwertasdfgzxcvb";
string l = "yuiophjklnm";

//ture -> right false -> left
bool check(char c) {
	bool flag = false;
	rep(i, sz(r)) {
		if (r[i] == c)flag = true;
	}
	return flag;
}

int main() {
	while (true) {
		string s; cin >> s;
		if (s == "#")break;

		vector<bool> f;
		rep(i, sz(s)) {
			f.pb(check(s[i]));
		}
		int cnt = 0;
		rep(i, sz(f) - 1) {
			if (f[i] != f[i + 1])cnt++;
		}
		cout << cnt << endl;
	}
}
