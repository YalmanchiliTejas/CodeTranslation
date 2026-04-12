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
set<int> stamp;
vector<int> tar(3);
set<int> exist;

int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int h, w;
		cin >> h >> w;
		REP(l, h + 3)
			REP(m, w + 3) {
			int add = 0;
			REP(k, h)
				REP(j, w) {
				int y = l - h + 1 + k;
				int x = m - w + 1 + j;
				if (0 <= y&&y <= 3 && 0 <= x&&x <= 3) {
					add |= 1 << (y * 4 + x);
				}
			}
			stamp.insert(add);
		}
	}
	REP(i, 4) {
		string s;
		cin >> s;
		REP(j, 4) {
			if (s[j] == 'R')
				tar[0] |= 1 << (i * 4 + j);
			if (s[j] == 'G')
				tar[1] |= 1 << (i * 4 + j);
			if (s[j] == 'B')
				tar[2] |= 1 << (i * 4 + j);
		}
	}
	exist.insert(0);
	queue<pii> Q;
	Q.push({ 0,0 });
	int ans = 17;
	while (!Q.empty()) {
		pii state = Q.front();
		Q.pop();
		if (state.first == (1 << 16) - 1) {
			ans = min(ans, state.second);
			break;
		}
		for (auto x : stamp) {
			REP(w, 3) {
				int copy = state.first;
				copy = copy&(((1 << 16) - 1) - x);
				copy |= x&tar[w];
				if (exist.find(copy) == exist.end()) {
					exist.insert(copy);
					Q.push({ copy, state.second + 1 });
				}
			}
		}
	}
	cout << ans << endl;
}