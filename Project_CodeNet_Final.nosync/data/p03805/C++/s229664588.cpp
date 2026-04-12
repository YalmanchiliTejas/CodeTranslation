# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = std::numeric_limits<long long>::max();
const double PI = acos(-1);
#define fir first
#define sec second
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, s, t, q, ans, sum, last, cnt, a[100];
struct Edge { LL to,cost; };
vector<Edge>vec[100];
string str;
bool f=0;
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
LL dfs(LL v, LL p, bitset<8>bi = {}) {
	LL ss = 0;
	bool f = 0;
	bi[v-1] = 1;
	if (bi.count() == n)return 1;
	rep(i, vec[v].size()) {
		if (vec[v][i].to != p&&bi[vec[v][i].to-1]==0) {
			
			ss += dfs(vec[v][i].to, v, bi);
			f = 1;
		}
	}
	if (f == 0)return 0;
	return ss;
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		LL x, y;
		cin >> x >> y;
		vec[x].push_back(Edge{ y,1 });
		vec[y].push_back(Edge{ x,1 });
	}
	cout << dfs(1,-1) << endl;
	return 0;
}