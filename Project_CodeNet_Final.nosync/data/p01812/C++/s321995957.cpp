#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <functional>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dx[] = { -1, 0, 1, 0 }; const int dy[] = { 0, 1, 0, -1 };

struct UnionFind {
	vector<int> v;
	UnionFind(int n) : v(n) { for (int i = 0; i < n; i++) v[i] = i; }
	int  find(int x) { return v[x] == x ? x : v[x] = find(v[x]); }
	void unite(int x, int y) { v[find(x)] = find(y); }
};
struct state {
	unsigned short d;
	int ans;
};
int n, m, c;
vi dp;
vi dark;
map<int, int> darks;
vvi cnct;
int calc(int num) {
	if (dp[num] == 998)
		return 998;
	if (dp[num] != 999)
		return dp[num];
	dp[num] = 998;
	REP(i, c) {
		int local=0;
		REP(j, m)
			if (((num >> j) & 1) && darks.count(cnct[dark[j]][i]) != 0)
				local |= 1 << darks[cnct[dark[j]][i]];
		if(local!=num)
		dp[num] = min(dp[num],calc(local)+1);
	}
	return dp[num];
}
int main() {
	cin >> n >> m >> c;
	dark.resize(m);
	REP(i, m) {
		cin >> dark[i];
		darks[dark[i]] = i;
	}
	cnct.resize(n + 1, vi(c));
	FOR(i, 1, n + 1)
		REP(j, c)
		cin >> cnct[i][j];
	dp.resize(1<<m,999);
	dp[0] = 0;
	cout << calc((1<<m)-1) << endl;
}