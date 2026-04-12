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
#include <climits>
#include <bitset>
#include <cassert>
#include <random>
#include <complex>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int dist[1 << 16];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> h(n), w(n);
	rep(i, n) cin >> h[i] >> w[i];
	vector<string> board(4);
	rep(i, 4) cin >> board[i];

	set<P> x;
	rep(i, n) rep(r, 8) rep(c, 8) for(char col: string("RGB")){
		int mask = 0;
		int ok = 0;

		char b[12][12] = {};
		for (int j = r; j < r + h[i]; ++j){
			for (int k = c; k < c + w[i]; ++k){
				b[j][k] = col;
			}
		}
		for (int j = 4; j < 8; ++j){
			for (int k = 4; k < 8; ++k){
				if (!b[j][k]) continue;
				int y = 1 << ((j - 4) * 4 + k - 4);
				mask |= y;
				if (b[j][k] == board[j - 4][k - 4]) ok |= y;
			}
		}
		x.insert(MP(mask, ok));
	}

	queue<int> q;
	q.push(0);
	MEMSET(dist, -1);
	dist[0] = 0;
	while (!q.empty()){
		int s = q.front();
		q.pop();

		for (auto p : x){
			int nxt = (s&~p.first) | p.second;
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[s] + 1;
			if (nxt + 1 == (1 << 16)){
				cout << dist[nxt] << endl;
				return 0;
			}
			q.push(nxt);
		}
	}
	cout << -1 << endl;
	
	return 0;
}