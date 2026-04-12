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

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200, mod = 1e9 + 7;

string s;
int k;
int d[10003][10][2][101];

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> k;
	for (int i = 0; i < s.size(); i++){
		int x = s[i] - '0';
		if (!i){
			for (int j = 0; j < x; j++){
				d[i][j][0][j % k] = 1;
			}
			d[i][x][1][x % k] = 1;
		}
		else{
			for (int o = 0; o < k; o++){
				int y = s[i - 1] - '0';
				for (int j = 0; j < x; j++){
					(d[i][j][0][(o + j) % k] += d[i - 1][y][1][o]) %= mod;
				}
				(d[i][x][1][(o + x) % k] += d[i - 1][y][1][o]) %= mod;
			}
			for (int o = 0; o < k; o++){
				for (int y = 0; y < 10; y++){
					for (int j = 0; j < 10; j++){
						(d[i][j][0][(o + j) % k] += d[i - 1][y][0][o]) %= mod;
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++){
		(ans += (d[s.size() - 1][i][0][0] + d[s.size() - 1][i][1][0]) % mod) %= mod;
	}
	cout << (ans - 1 + mod) % mod;
	return 0;
}










