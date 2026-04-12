#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, e) for(int i = (int)(b); i < (int)(e); i++)
#define rep(i, n) REP(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<int> es[21];
int n, m;

ll dp[8][(1<<8)];

ll f(int p, int mask) {
	if(dp[p][mask] != -1) return dp[p][mask];
	if(mask == ((1<<n)-1)) return dp[p][mask] = 1LL;
	ll ret = 0LL;
	for(auto& to : es[p]) {
		if(mask & (1 << to)) continue;
		int nxt = mask | (1<< to);
		ret += f(to, nxt);
	}
	return dp[p][mask] = ret;
}

int main(){
	cin>>n>>m;
	rep(i, m){
		int a, b;
		cin>>a>>b;	
		a--;
		b--;
		es[a].pb(b);
		es[b].pb(a);
	}
	rep(i, 8) rep(j, 1<<8) dp[i][j] = -1;
	cout<<f(0, 1)<<endl;
}
