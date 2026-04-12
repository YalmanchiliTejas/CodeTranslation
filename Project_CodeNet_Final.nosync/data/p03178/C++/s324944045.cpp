#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 
#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
 
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
  
#define pb push_back
#define mp make_pair
#define in insert
#define f first
#define s second
#define ll long long
#define dd double
  
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int inf = 2e9;
const ll INF = 1e18;

ll dp[N][101][2];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("*.in", "r", stdin);freopen("*.out", "w", stdout);
	string s;
	int d;
	cin >> s >> d;

	for (int i = 0; i < s[0] - '0'; i++) {
		dp[0][i % d][0]++;
	}
	dp[0][(s[0] - '0') % d][1]++;

	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j < d; j++) {
			for (int x = 0; x < s[i] - '0'; x++) {
				(dp[i][(j + x) % d][0] += dp[i - 1][j][1]) %= mod;
			}

			(dp[i][(j + s[i] - '0') % d][1] += dp[i - 1][j][1]) %= mod;

			for (int x = 0; x < 10; x++) {
				(dp[i][(j + x) % d][0] += dp[i - 1][j][0]) %= mod;
			}
		}
	}

	cout << ((dp[s.size() - 1][0][0] + dp[s.size() - 1][0][1]) % mod - 1 + mod) % mod;
}