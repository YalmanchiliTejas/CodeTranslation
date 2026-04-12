#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<lli> vi;
typedef vector<vi> vvi;
const int mod = 1e9+7;
#define MAXN 10005
lli dp[MAXN][105][3];
string s;
int d,n;

lli solve(int pos, int sum, int f){
	if(pos == n){
		if(sum == 0) return 1;
		return 0;
	}

	if(dp[pos][sum][f] != -1) return dp[pos][sum][f];
	
	int limit = 9;
	if(!f) limit = s[pos] - '0';
	lli ans = 0ll;
	for(int i=0; i <= limit; i++){
		ans = (ans + solve(pos+1,(sum + i)%d,(i < (s[pos]-'0')) | f)%mod)%mod;
	}
	return dp[pos][sum][f] = ans;
}

int main(){__
	cin >> s;
	n = s.size();
	cin >> d;
	memset(dp,-1,sizeof(dp));
	lli ans = solve(0,0,0) % mod;
	cout << (ans + mod -1 ) % mod << endl;
	return 0;
}
