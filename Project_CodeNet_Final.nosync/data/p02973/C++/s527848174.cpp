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


int main() {
	ll n; cin >> n;
	ll x[100100];
	REP(i, n)cin >> x[i];
	vector<ll>a(n);
	for (int i = n - 1; i >= 0; --i) {
		a[n - 1 - i] = x[i];
	}
	vector<int>dp(100100);//dp[i]:=i+1の部分列の最後の要素となる最小の値
	REP(i, 100100)dp[i] = INF;
	for (int i = 0; i < n; ++i) {
		*upper_bound(dp.begin(),dp.end(), a[i]) = a[i];
	}
	cout << (lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << endl;
	return 0;
}
