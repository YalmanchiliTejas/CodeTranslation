#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 1e18;
const double PI = acos(-1);

vll VL,VM;

ll dfs(int LV, ll rest) {
	if (LV == 0)return 1;
	if (rest >= VL[LV]) {
		return VM[LV];
	}
	ll ret = 0;
	rest -= 1;
	if (rest <= 0)return ret;
	ret += dfs(LV - 1, rest);
	rest -= VL[LV - 1];
	if (rest <= 0)return ret;
	ret++;
	rest--;
	if (rest <= 0)return ret;
	ret += dfs(LV - 1, rest);
	rest -= 1;
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N, X;
	cin >> N >> X;
	VL.push_back(1);
	VM.push_back(1);
	ll lv_pre = 1;
	ll meat = 1;
	REP(i, N) {
		lv_pre *= 2;
		lv_pre += 3;
		meat *= 2;
		meat += 1;
		VL.push_back(lv_pre);
		VM.push_back(meat);
	}
	cout << dfs(N, X) << endl;
	PAU;
	return 0;
}
