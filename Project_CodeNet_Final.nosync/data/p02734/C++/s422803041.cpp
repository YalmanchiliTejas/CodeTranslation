// cities to vapori-
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz // math is your friend
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 3050, MOD = 998244353;

int n,k;
int a[N];
ll dp[N][N];

ll go(int id, int rem){
	ll &ans = dp[id][rem];
	if(ans != -1) return ans;
	if(rem == 0) return ans = n-id+1;
	if(id == n) return ans = 0;
	ans = go(id+1,rem);
	if(rem-a[id] >= 0) ans = (ans + go(id+1,rem-a[id])) % MOD;
	return ans;
}

int main(){

	fastio;
	cin >> n >> k;
	REP(i,0,n) cin >> a[i];

	ll ans = 0;
	fill(dp,-1);
	for(int i = 0; i < n; ++i){
		if(k-a[i] >= 0){
			ans = (ans + ((go(i+1,k-a[i])*(i+1))%MOD)) % MOD;
		}
	}
	cout << ans << endl;

	return 0;
}
