#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int N = 1e5 + 10;

vector<int> G[N];


int main(){	
	int n, m;
	cin >> n >> m;
	string s;
	rep(i, n){
		char c;
		cin >> c;
		s += c;
	}
	rep(i, m){
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);
	}

	rep(i, n){
		if (s[i] != '?') continue;
		set<char> st;
		for (auto v : G[i]){
			st.insert(s[v]);
		}
		rep(j, 26){
			if (st.count('a' + j)) continue;
			s[i] = 'a' + j;
			break;
		}
	}
	cout << s << endl;

	return 0;
}
