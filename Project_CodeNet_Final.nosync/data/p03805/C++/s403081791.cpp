#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll n,m;

vector<ll> G[10];

ll used[10];

ll dfs(ll i,ll d) {
	if(d == n) {
		return 1;
	}

	ll ret = 0;
	REP(j,G[i].size()) {
		if(!used[G[i][j]]) {
			used[G[i][j]] = true;
			ret += dfs(G[i][j],d + 1);
			used[G[i][j]] = false;
		}
	}
	return ret;
}

int main(){
	cin  >> n >> m;

	REP(i,m) {
		int a,b;
		cin >> a >> b;
		a--;b--;

		G[a].pb(b);
		G[b].pb(a);
	}

	used[0] = true;
	cout << dfs(0,1) << endl;
	return 0;
}