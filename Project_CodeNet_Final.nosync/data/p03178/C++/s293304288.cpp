/*
 * 
 * */

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << ":\t" << x << endl
#define _ << " " <<

#define s_time clock_t time_start = clock()
#define t_time cout << double(clock() - time_start) / 1000 << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int N = 1e4 + 3;
const int D = 101;
const ll M = 1e9 + 7;

string s;
int d, digit;
ll dp[N][D], res;

int main(int argc, char** argv) {
//	mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> s >> d;
	digit = s.size();
	
	dp[0][0] = 1;
	for (int i = 0; i <= digit; ++i) {
		for (int j = 0; j < d; ++j) {
			dp[i][j] %= M;
			for (int k = 0; k <= 9; ++k) {
				dp[i+1][(j + k) % d] += dp[i][j];
			}
		}
	}
	
	ll sum = 0;
	for (int i = 1; i <= digit; ++i) {
		int num = s[i-1] - '0';
		for (int k = 0; k < num; ++k) {
			(res += dp[digit - i][(d + d - (sum + k % d)) % d]) %= M;
		}
		sum = (sum + num) % d;
	}
	
	(res += M - 1) %= M;
	if (sum == 0) ++res;
	cout << res;
	
	return 0;
}

/*
 * 
 * */
