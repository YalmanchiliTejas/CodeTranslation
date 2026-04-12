/*
    JAI JAGANNATH!
*/
//@Author : zanj0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
}
const int N = 1e4 + 5;
const int M = 105;
int dp[N][M][2];
int n, m;
string num;
int d;
int add(lli a, lli b) {
	return ((a % mod) + (b % mod)) % mod;
}
lli help(lli idx, lli sum, lli flag) {
	if (idx == n) {

		return sum == 0;
	}
	if (dp[idx][sum][flag] != -1) return dp[idx][sum][flag];
	lli ret = 0;
	if (flag) {
		for (int i = 0; i <= num[idx] - '0'; i++) {
			ret = add(ret, help(idx + 1, (sum + i) % d , i == num[idx] - '0'));
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			ret = add(ret, help(idx + 1, (sum + i) % d , 0));
		}
	}
	return dp[idx][sum][flag] = ret;
}
void solve() {
	memset(dp, -1, sizeof dp);
	cin >> num;
	cin >> d;
	n = num.size();
	cout << ((help(0, 0, 1) % mod - 1 % mod) + mod) % mod << endl;
}
int main()
{
	zanj0();
	solve();
	return 0;
}
