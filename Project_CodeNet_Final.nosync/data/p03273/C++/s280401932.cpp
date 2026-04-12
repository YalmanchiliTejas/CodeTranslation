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

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 2.0 * asin(1.0);
const ll INF = 1L<<60;
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MAX = 10000000;
/****** define constant end ********/
/****** define variable start ******/
ll h, w;
vector<string> a;
/******* define variable end *******/
int solve() {
	cin >> h >> w;
	a.resize(h);
	REP(i, h){
		cin >> a[i];
	}
	vector<string> ans;
	REP(i, h){
		bool flag = true;
		REP(j, w){
			if(a[i].substr(j, 1) == "#"){
				flag = false;
			}
		}
		if(!flag){
			ans.push_back(a[i]);
		}
	}
	vector<vector<string>> ans2(ans.size());
	REP(i, ans[0].size()){
		bool flag = true;
		REP(j, ans.size()){
			if(ans[j].substr(i, 1) == "#"){
				flag = false;
			}
		}
		if(!flag){
			REP(j, ans.size()){
				ans2[j].push_back(ans[j].substr(i, 1));
			}
		}
	}
	REP(i, ans.size()){
		REP(j, ans2[0].size()){
			cout << ans2[i][j];
		}
		cout << endl;
	}
	return 0;
}

int main() {
	//clock_t start = clock();
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
