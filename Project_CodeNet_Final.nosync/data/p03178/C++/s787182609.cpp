#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ll long long
#define ld long double
#define vvi vector<vi>
#define vll vector<ll>
#define vld vector<ld>
#define vvll vector<vll>
#define vvld vector<vld>
#define MOD 1000000007
#define endL << '\n'
#define ii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define endL << '\n'
#define vii vector<ii>
#define pb push_back

/*
ll powmod(ll x, ll y, ll mod){
	ll res = 1;
	while (y > 0){
		if (y%2) res = (res*x) % mod;
		x = (x*x) % mod;
		y /= 2;
	}
	return res;
}
*/

/*const int N = 1000000;
int lp[N+1];
vector<ll> pr;

void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}*/
const int M = 1e4+1;
int D, n;
string K;

int dp[M][2][101];

int recurse(int pos, int tight, int sum){
	if (pos == n){
		return ((sum == 0) ? 1 : 0);
	}
	if (dp[pos][tight][sum] != -1){
		return dp[pos][tight][sum];
	}

	int ans = 0;

	int up = (tight ? (K[pos] - '0') : 9);
	for (int d = 0; d <= up; d++){
		ans = (ans + recurse(pos+1, (tight && !(d < K[pos] - '0')), (sum + d) % D)) % MOD;
	} 

	return (dp[pos][tight][sum] = ans);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1; //cin >> t;
	while(t--){
		cin >> K;
		cin >> D;
		n = K.length();
		memset(dp, -1, sizeof(dp));
		cout << (recurse(0, 1, 0) -1 + MOD) % MOD;

	}
}
