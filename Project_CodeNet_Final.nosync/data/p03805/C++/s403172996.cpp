#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <set>
#include <cstdio>
#include <bitset>
#include <functional>
#include <tuple>
using namespace std;
const constexpr int INF = 1e9;
//typedef std::pair<std::string,double> P;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef vector<int> VI;
const constexpr ll MOD = 1e9 + 7;

struct Less {
	bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
		return x.first > y.first;
	}
};
//グラフの隣接リスト
//VI g[200010];
//頂点の入次数を管理
int h[100010];

bool g[101][101];

int N, M;
//int dxy[5] = { -1, 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	REP(i, N) REP(j, N) g[i][j] = false;

	REP(i, M) {
		int a, b; cin >> a >> b;
		g[a - 1][b - 1] = true;
		g[b - 1][a - 1] = true;
	}
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		v.push_back(i);
	}
	int cnt = 0;
	bool t[101][101];
	do{
		REP(i, N) REP(j, N) t[i][j] = g[i][j];
        if(v[0]!=0) continue;
		bool ok = true;
		int tmp = v[0];
		for (int i = 1; i < (int)v.size(); ++i) {
			if (t[tmp][v[i]]) {
                t[tmp][v[i]] = false;
                t[v[i]][tmp] = false;
				tmp = v[i];
			}
			else {
				ok = false;
				break;
			}
			
		}
		if (ok) cnt++;
	} while (next_permutation(v.begin(), v.end()));
    
    cout << cnt << endl;
	return 0;
}