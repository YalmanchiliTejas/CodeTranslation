#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int n, m;
vector<int> es[10];

int memo[10][1<<10];

int dfs(int now, int mask_past) {
	if(memo[now][mask_past] != 0) return memo[now][mask_past];
	int ret = 0;
	for(int i = 0; i < es[now].size(); i++) {
		int nxt = es[now][i];
		if(mask_past & (1 << nxt)) continue;
		int mask_nxt = mask_past | (1 << nxt);
		ret += dfs(nxt, mask_nxt);
	}
	if(mask_past == (1<<n)-1) ret = 1;
	return memo[now][mask_past] = ret;
}

int main(){
	cin >> n >> m;
	rep(i, m) {
		int a, b; 
		cin >> a >> b;
		a--;b--;
		es[a].pb(b);
		es[b].pb(a);
	}
	cout << dfs(0, 1) << endl;
}
