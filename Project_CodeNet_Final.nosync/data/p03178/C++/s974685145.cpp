#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<ll,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

// fim da Prioridade
ll dp[10004][104][2];
int k, n;
string t;
ll solve(int i,int r,int ok){
	if(i == n && r == 0){
		return 1LL;
	}else if(i == n){
		return 0LL;
	}
	if(dp[i][r][ok] != -1){
		return dp[i][r][ok] ;
	}
	int digit = t[i] - '0';
	if(ok)
		digit = 9;
	ll ans = 0LL;
	for(;digit >=0;digit--){
		ans = (ans + solve(i+1,(r+digit)%k,ok || ((t[i] - '0') > digit)))%MOD;
	}
	return dp[i][r][ok]=  ans%MOD;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t >> k;
	n = t.size();
	memset(dp,-1,sizeof dp);
	cout << (solve(0,0,0) - 1LL +MOD)%MOD << endl;
	return 0;
}
