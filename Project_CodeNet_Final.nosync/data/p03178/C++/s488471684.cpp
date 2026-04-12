#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int dp[101][10001][2], d;
string s;

int solve(int i, int val, int tight) { 
	val %= d;
	if (i == s.length()) {
		if (val % d == 0) {
			return 1;
		}
		return 0;
	}

	if (dp[val][i][tight] != -1) {
		return dp[val][i][tight];
	}

	int limit = 9, ans = 0;
	if (!tight) {
		for (int num = 0; num <= limit; num++) {
			ans += solve(i + 1, val + num, tight);
			ans %= mod;
		}	
	}

	if (tight) {
		limit = s[i] - '0';
		for (int num = 0; num < limit; num++) {
			ans += solve(i + 1, val + num, !tight);
		}	
		ans += solve(i + 1, val + limit, tight);
		ans %= mod;
	}

	return dp[val][i][tight] = ans;
} 

void c_p_c()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
   cin >> s >> d;
   memset(dp, -1, sizeof dp);
   cout << (solve(0, 0, 1) - 1 + mod) % mod; // excluding zero

}
 
int32_t main()
{
    c_p_c();
    return 0;
}