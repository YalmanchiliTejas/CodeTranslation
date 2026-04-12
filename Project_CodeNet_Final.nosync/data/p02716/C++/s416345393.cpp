#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
ll prefix[200005], a[200005], dp[200005];
int main(){
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	prefix[1] = a[1];
	for (ll i = 3; i <= n; i += 2) prefix[i] = prefix[i - 2] + a[i];
	for (ll i = 2; i <= n; i++){
		if (i % 2 == 1) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		else dp[i] = max(prefix[i - 1], dp[i - 2] + a[i]);
	}
	cout << dp[n] << endl;
}