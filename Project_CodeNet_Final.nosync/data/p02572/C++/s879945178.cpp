#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;
struct Edge {
	ll to;
 	ll cost;
 };
using Graph = vector<vector<Edge>>;

const int MAX = 10000000;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 3.1415926535897932;
const ll INF = LLONG_MAX;
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/****** define constant end ********/

/****** define variable start ******/
ll n;
vl a;
/******* define variable end *******/
int solve() {
	cin >> n;
	a.resize(n);
	vl sumvec(n+1);
	sumvec[0] = 0;
	REP(i, n){
		cin >> a[i];
		sumvec[i+1] = sumvec[i] + a[i];
		sumvec[i+1] %= MOD;
	}
	ll ans = 0;
	REP(i, n){
		ans += (sumvec[n] + MOD  - sumvec[i+1]) * a[i];
		ans %= MOD;
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}

int main() {
	// clock_t start = clock();
	cout << std::fixed << std::setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int end_solve = solve();
	/*
	clock_t end = clock();
	const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC *
	1000.0; printf("time %lf[ms]\n", time);
	*/

	return end_solve;
}
