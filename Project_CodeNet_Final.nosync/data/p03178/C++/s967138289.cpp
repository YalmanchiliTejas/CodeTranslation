//apigs property
//Happiness can be found, even in the darkest of times, if one only remembers to turn on the light
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second
#define pb push_back
#define vll vector< ll >
#define vi vector< int >
#define pll pair< ll , ll >
#define pi pair< int , int >
#define all(s) s.begin() , s.end()
#define sz(s) s.size()
#define md (s + e) / 2
#define mid (l + r) / 2
#define msdp(dp) memset(dp , -1 , sizeof dp)
#define mscl(dp) memset(dp , 0 , sizeof dp)
#define C continue
#define R return
#define lx node * 2
#define rx node * 2 + 1
using namespace std;
typedef long long  ll;
ll q, dp[105][100005][2], k, n;
string s;
const ll mod = 1e9 + 7;
ll mem(ll sum , ll i , ll op){
	//cout << sum << " " << i << " " << op << endl;
	if(i == n)R (sum == 0LL ? 1LL : 0LL);
	ll &r = dp[sum][i][op];
	if(r != -1)R r;
	r = 0LL;
	ll oo = 9LL;
	if(op) oo = s[i] - '0';
	for(ll j = 0 ; j <= oo ; j++){
		if(op && j == s[i] - '0')r = (r % mod + mem((sum + j) % k , i + 1 , 1) % mod + mod) % mod;
		else r = (r % mod + mem((sum + j) % k , i + 1 , 0) % mod + mod) % mod;
	}
	r = (r + mod) % mod;
	R r;
}
void solve(){
	msdp(dp);
	cin >> s >> k;
	n = sz(s);
	cout << (mem(0 , 0 , 1) - 1 + mod) % mod << endl;
}
int main(){
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}


