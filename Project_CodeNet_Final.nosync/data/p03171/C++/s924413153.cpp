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
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

int n, m, k;
int a[N];
int d[3001][3001][3];

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++){
		for (int l = 0, r = i - 1; r < n; l++, r++){
			if (i == 1){
				d[l][r][1] = a[l];
				d[l][r][0] = -a[l];
			}
			else{
				d[l][r][1] = max(d[l + 1][r][0] + a[l], d[l][r - 1][0] + a[r]);
				d[l][r][0] = min(d[l + 1][r][1] - a[l], d[l][r - 1][1] - a[r]);
			}
		}
	}
	cout << d[0][n - 1][1];
	return 0;
}










