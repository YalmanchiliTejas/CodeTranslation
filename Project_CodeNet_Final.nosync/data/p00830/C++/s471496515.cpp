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
#include <cassert>

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
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> P;

int num;
const int N = 1010;
map<string, int> G[N];
int par[N];
int file[N];

bool f;
string ind = "index.html";

vector<string> path;
int dfs(int id, int i, bool create){
	if (id < 0) return -1;
	if (i == path.size()){
		if (file[id]) return id;
		return G[id].count(ind) && file[G[id][ind]] ? G[id][ind] : -1;
	}
	if (file[id]) return -1;
	if (path[i] == ".") return dfs(id, i + 1, create);
	if (path[i] == "..") return dfs(par[id], i + 1, create);
	if (G[id].count(path[i])){
		return dfs(G[id][path[i]], i + 1, create);
	}
	else{
		if (create){
			G[id][path[i]] = num;
			file[num] = i == path.size() - 1; // dir or file
			par[num++] = id;
			return dfs(G[id][path[i]], i + 1, create);
		}
		else {
			return -1;
		}
	}
}

vector<string> parse(string s){
	rep(i, s.size()){
		if (s[i] == '/') s[i] = ' ';
	}
	stringstream ss(s);
	vector<string> res;
	while (ss >> s) res.push_back(s);
	return res;
}

int main(){
	ios::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m, n){
		num = 1;
		rep(i, N) G[i].clear();
		rep(i, N) par[i] = -1;

		rep(i, n){
			string s;
			cin >> s;
			path = parse(s);
			dfs(0, 0, true);
		}
		rep(i, m){
			string s, t;
			cin >> s >> t;

			if (s.back() == '/') s += ".";
			path = parse(s);
			int a = dfs(0, 0, false);

			if (t.back() == '/') t += ".";
			path = parse(t);
			int b = dfs(0, 0, false);

			if (a < 0 || b < 0) cout << "not found" << endl;
			else if (a != b) cout << "no" << endl;
			else cout << "yes" << endl;
		}
	}

	return 0;
}