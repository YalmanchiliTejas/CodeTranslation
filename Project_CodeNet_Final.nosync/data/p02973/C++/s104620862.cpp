#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { -1, 0, 0, 1 };
const ll dy[4] = { 0, -1, 1, 0 };
const ll INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
struct Accelerate_Cin {
	Accelerate_Cin() {
		cin.tie(0);
		ios::sync_with_stdio(0);
		cout << fixed << setprecision(20);
	};
};
///////////////////////////////////////

//結論から言うと広義単調減少列の長さの最大値Lである。これを証明する
//数列の後ろから順にどの色で塗るかを決めていく最も後ろの要素に関しては何らかの色で
//塗る必要がありかつ他の要素に色は着いていないので適当に1色で塗っておく
//後ろから2番目以降の数Aiに関しては各色cで塗られている要素の内現在の最小の値Bcはいくつか
//を考える。まずBc<=AiならばAiをcで塗ることは条件に反するためできない。

int main() {
	ll n; cin >> n;
	vector<ll>a(n);
	REP(i, n)cin >> a[i];
	multiset<ll>s;
	for (ll i = 0; i < n; ++i) {
		ll now = a[i];
		auto itr = s.lower_bound(now);
		if (itr != s.begin())s.erase(--itr);
		s.insert(now);
	}
	cout << s.size() << endl;
	return 0;
}
