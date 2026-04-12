#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define ppll pair <pll, pll>
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
#pragma 03
using namespace std;
using namespace __gnu_pbds;
int main() {
  	string s; cin >> s;
  	ll l = s.length();
    ll n[l];
  	for (ll i = 0; i<l; i++) n[i] = s[i] - '0';
  	ll k; cin >> k;
  	ll c = 1;
  	ll dp[l][k+1] = {};
  	dp[0][0] = 1;
  	dp[0][1] = n[0] - 1;
  	for (ll i = 1; i<l; i++){
    	dp[i][0] = 1;
    	for (ll j = 1; j <= k; j++) dp[i][j] = dp[i-1][j-1] * 9 + dp[i-1][j];
    	if (n[i] > 0){
      		if (c <= k) dp[i][c] += 1; c++;
      		if (c <= k) dp[i][c] += n[i] - 1;
    	}
  	}
  	if (c == k) dp[l-1][k]++;
  	cout << dp[l-1][k] << endl;
}