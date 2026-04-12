
// Problem : 
// 			E - Almost Everywhere Zero
// 			Editorial
// 		
// Contest : AtCoder - AtCoder Beginner Contest 154
// URL : https://atcoder.jp/contests/abc154/tasks/abc154_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀
⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀
⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀
⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲⣿⠀
⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀
⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀⡿⠀⠀
⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀
⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀
⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀
⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀
⣿⣿⣧⣀⣿.........⣀⣰⣏⣘⣆⣀⠀
*/
#include <bits/stdc++.h> 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long   ll;
typedef long double ld;
typedef complex< ld > cd;
 
typedef pair<int, int> pi;
typedef pair<ll, ll>   pl;
typedef pair<ld, ld>   pd;
 
typedef vector< int > vi;
typedef vector< ld >  vd;
typedef vector< ll >  vl;
typedef vector< pi >  vpi;
typedef vector< pl >  vpl;
typedef vector< cd >  vcd;
 
#define l00p(i, a, b) for (int i=a; i<(b); i++)
#define loop(i, a)    for (int i=0; i<(a); i++)
#define rep1(i, a, b) for (int i = (b)-1; i >= a; i--)
#define rep(i, a)     for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)    for (auto& a : x)
#define uid(a, b)     uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f  first
#define s  second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
//#define MOD 998244353
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld pii=3.14159265359; 
const int MOD = 1000000007;
const char nl = '\n';
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
string n;
int k;
ll dp[101][3][2];
ll rec(int ind,int left,bool low)
{
		if(left==0)
		return 1;
		if(ind == sz(n))
		return 0;
		if(dp[ind][left][low]!=0)
		return dp[ind][left][low];
		int r=low ? 9:n[ind]-'0';
		ll ans=0;
		loop(i,r+1)
		ans+=rec(ind+1,left-(i!=0),low||(i<n[ind]-'0'));
		dp[ind][left][low]=ans;
		return dp[ind][left][low];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	cin>>n>>k;
	cout<<rec(0,k,0);
	memset(dp,-1,sizeof dp);
	return 0;
}
// read the question correctly (ll vs int)
// template by bqi343