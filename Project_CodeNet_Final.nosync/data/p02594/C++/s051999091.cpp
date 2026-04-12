#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;
struct Edge {
	ll to;
	ll cost;
};
using Graph = vector<vector<Edge>>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define RES(a, n) (a).resize(n)
#define VLCIN(a, n) REP(i,n){cin >> a[i];}
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 2.0 * asin(1.0);
const ll INF = 1L<<60;
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MAX = (ll)pow(10,7);
/****** define constant end ********/
/****** define variable start ******/
ll x;
/******* define variable end *******/
int solve() {
	cin >> x;
	if(x >= 30){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
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
