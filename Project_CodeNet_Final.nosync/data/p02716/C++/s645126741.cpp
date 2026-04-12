#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pair_t;
using Graph = vector<vector<ll>>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 3.1415926535897932;
const ll INF = 1 << 29;
/****** define constant end ********/
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
	if (n & 1)
	  res = res * a % mod;
	a = a * a % mod;
	n >>= 1;
  }
  return res;
}
/****** define variable start ******/
ll n;
vl a;
/******* define variable end *******/
int solve() {
	cin >> n;
	a.resize(n);
	REP(i, n){
		cin >> a[i];
	}
	if(n % 2 == 0){
		vl left(n/2+1);
		vl right(n/2+1);
		left[0] = a[0];
		right[0] = a[1];
		for(ll i = 1; i < n / 2; i++){
			left[i] = left[i-1] + a[2*i];
			right[i] = max(left[i-1], right[i-1]) + a[2*i + 1];
		}
		cout << max(left[n/2-1], right[n/2-1]) << endl;
	}else{
		vl left((n-1)/2 + 1);
		vl mid((n-1)/2 + 1);
		vl right((n-1)/2 + 1);
		left[0] = a[0];
		mid[0] = a[1];
		right[0] = a[2];
		for(ll i = 1; i < (n-1)/2; i++){
			left[i] = left[i-1] + a[2*i];
			mid[i] = max(left[i-1], mid[i-1]) + a[2*i + 1];
			right[i] = max({left[i-1], mid[i-1], right[i-1]}) + a[2*i + 2];
		}
		cout << max({left[(n-1)/2-1], mid[(n-1)/2-1], right[(n-1)/2-1]}) << endl;
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
