// copied by Nurstan Duisengaliev
// skatal                        
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) (int)x.size()
#define int ll 
using namespace std;
//using namespace __gnu_pbds;

//template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;                         

const int N = (int)2e5 + 123;
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
string a;
int d;
int kol1[10001][101];
int kol2[10001][101];
void solve () {
	cin >> a >> d;
	int n = sz (a);
	for (int i = 1; i <= 9; i ++) {
		kol1[1][i % d] ++;  \
		kol2[1][i % d] ++;
	}
	kol2[1][0] ++;
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < d; j ++) {
			for (int o = 0; o <= 9; o ++) {
				if (o == 0) {
					kol2[i + 1][j] += (kol2[i][j] % mod);
					kol2[i + 1][j] %= mod;		
				}
				else {
					kol2[i + 1][(j + o) % d] += (kol2[i][j] % mod);
				    kol1[i + 1][(j + o) % d] += (kol2[i][j] % mod);
				    kol1[i + 1][(j + o) % d] %= mod;
				    kol2[i + 1][(j + o) % d] %= mod;
				}
			}
		}
	}
	kol2[0][0] = 1;
	ll ans = 0;
	for (int i = 1; i < n; i ++) {
		ans += (kol1[i][0]);
		ans %= mod;		
	}
	int sum = 0;
	for (int i = 0; i < n; i ++) {
		if (i == 0) {
			for (int j = 1; j < a[i] - '0'; j ++) {
				ans += kol2[n - i - 1][(d - ((sum + j) % d)) % d];
				ans %= mod;		
			}
		}	
		else {
		    for (int j = 0; j < a[i] - '0'; j ++) {
		    	ans += kol2[n - i - 1][(d - ((sum + j) % d)) % d];
				ans %= mod;	
		    }
		}
		sum += a[i] - '0';
	}
	if (sum % d == 0) ans ++;
	ans %= mod;
	cout << ans << endl;
}   	
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//    cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}