#include "bits/stdc++.h"
#define int long long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi vector<vector<int>>
#define vi vector<int>
#define f first
#define s second
using namespace std;
const int mod = 1e9 + 7;
int logi(int n) {int p = 0; while (n / 2) {n = n / 2; p++;} return p;}
int poww(int x, int y) {int pro = 1; while (y) {if (y & 1)pro = ((pro % mod) * (x % mod) % mod); y = y >> 1; x = ((x % mod) * (x % mod) % mod);} return pro;}
int poww2(int x, int y) {int pro = 1; while (y) {if (y & 1)pro = pro * x; y = y >> 1; x = x * x;} return pro;}
bool isprime(int n) { if (n == 1) return false; for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false; return true;}
vector<vector<int>> adj(2e5);
vi dist(2e5, INT_MAX);
/*

*/

int solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		sum -= v[i];
		ans = ((ans % mod) + (((v[i]%mod) * (sum%mod)) % mod))%mod;
	}
	cout << ans;
	return 0;
}
int32_t main() {
	/*#ifndef ONLINE_JUDGE
	    //for getting input from input.txt
	    freopen("input.txt","r",stdin);
	    //for writing output to output.txt
	    freopen("output.txt","w",stdout);
	#endif*/
	fast;
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
