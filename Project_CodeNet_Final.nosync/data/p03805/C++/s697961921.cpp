#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
 
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef complex<double> P;
typedef complex<double> Vec;
typedef pair<int, int> pii;
typedef pair<int, pii> p;
 
#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-8)
#define PI (acos(-1))
const ll MOD = 1000000007ll;

int n, m;
vector<int> g[8];

int main() {
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<int> num(n);
	REP(i, n) num[i] = i;
	
	int ans = 0;
	do {
		if (num[0] != 0) continue;

		bool f = true;
		FOR(i, 1, n) {
			vector<int>::iterator it = find(ALL(g[num[i - 1]]), num[i]);
			if (it == g[num[i - 1]].end()) f = false;
		}
		if (f) ans++;
		
	} while (next_permutation(ALL(num)));
	
	cout << ans << endl;
	
	return 0;
}