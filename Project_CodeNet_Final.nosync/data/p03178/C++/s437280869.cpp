/* Press F to pay respects */
#define _CRT_SECURE_NO_DEPRECATE
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; 
using namespace std;
#define int long long int
#define SYNC std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii>   vii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, 
//             tree_order_statistics_node_update> 
//    data_set;
#define rep(i,l,r)   for(int i=(l);i<(r);i++)
#define deb(x)     cout << (#x) << " is " << (x) << endl
#define dbg(x)     cout << x << ' '
#define here cout << " Hey baitch!!\n";
#define  pb push_back
#define  F  first
#define  S  second
#define all(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
const int MOD = 1e9+7;
const int MOD1 = 998244353;
const int N = 2e5+5;
const int INF = 1000111000111000111LL;
const ld PI = 3.1415926535898;
int dp[10000][100][2];
int32_t main()
{
	SYNC
	string s;
	int d;
	cin >> s >> d;
	int n = sz(s);
	memset(dp,0,sizeof dp);
	for(int i = 0; i < (s[0]-'0'); i++)
		dp[0][i%d][0] += 1;
	dp[0][(s[0]-'0')%d][1] = 1;
	for(int i = 1; i < n; i++) {
		int cur_lim = s[i]-'0';
		for(int j = 0; j < d; j++) {
			for(int k = 0; k < 10; k++) {
				dp[i][(k+j)%d][0] += dp[i-1][j][0];
				dp[i][(k+j)%d][0] %= MOD;
				if(k < cur_lim) {
					dp[i][(k+j)%d][0] += dp[i-1][j][1];
					dp[i][(k+j)%d][0] %= MOD;
				}
			}
			if(dp[i-1][j][1]) {
				dp[i][(j+cur_lim)%d][1] += dp[i-1][j][1];
				dp[i][(j+cur_lim)%d][1] %= MOD;
			}	
		}
	}
	int ans = (dp[n-1][0][1]+dp[n-1][0][0] + MOD-1)%MOD;
	ans = max(ans,0LL);
	cout << ans;
    return 0;
}