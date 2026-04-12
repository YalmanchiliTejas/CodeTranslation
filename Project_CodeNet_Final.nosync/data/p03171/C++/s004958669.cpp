/* Author darklight13 -_- 
   IIT Patna 
*/
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
int n,dp[3005][3005];
vi a;
int play(int l, int r) {
	if(dp[l][r] != -1)	return dp[l][r];
	if(l > r)	return 0;
	if(l==r) {
		dp[l][r] = a[l];
		return a[l];
	}
	int res = max(a[l]-play(l+1,r),a[r]-play(l,r-1));
	dp[l][r] = res;
	return res;
}
int32_t main()
{
	SYNC
	cin >> n;
	memset(dp,-1,sizeof dp);
	a.resize(n);
	for(int &x : a)	cin >> x;
	cout << play(0,n-1);
    return 0;
}