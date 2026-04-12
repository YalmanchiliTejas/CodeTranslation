// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
void print(){cout << endl;} void prints(){}
template<typename T=int> T get(){T x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();

	int n = get();
	vi a(n); get(a,n);
 
	int dp[n+1][n+1][2];
	clear(dp);
 
	auto nmax = [=](int& x, int n) { x = max(x, n); };
 
	for (int len = 1; len <= n; len++){
		for(int l = 0; l <= n - len; l++){
			int r = n - (l+len);
			int p = len % 2;
			int x = dp[l+1][r][p] + a[l];
			int y = dp[l][r+1][p] + a[n-1-r];
			if (x > y){
				dp[l][r][p] = x;
				dp[l][r][p^1] = dp[l+1][r][p^1];
			} else {
				dp[l][r][p] = y;
				dp[l][r][p^1] = dp[l][r+1][p^1];
			}
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		prints(dp[j][i][0]);
	// 	}
	// 	print();
	// }
	// print();
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		prints(dp[j][i][1]);
	// 	}
	// 	print();
	// }
	// print();
 
	print((dp[0][0][0] - dp[0][0][1]) * int(pow(-1, n)));
	
	return 0;
}