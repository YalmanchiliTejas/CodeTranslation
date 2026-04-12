#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb emplace_back
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(auto i=(a); i<(b); i++)
#define dec(i,n,a) for(auto i=(n); i>=(a); i--)
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define EPS 5e-9
#define fcin ios_base::sync_with_stdio(false)
#define db(x) cerr << #x << " == " << x << endl
#define _ << " " <<
#define MAXN 505050
#define LOGN 18
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define int ll

int n, m, a, b;
ll dis[MAXN], pdvai[MAXN], pdvem[MAXN], mod = 1e9+7;
vi adj[MAXN], cost[MAXN], pai[MAXN], vai[MAXN], vem[MAXN];
char jav[MAXN], pvai[MAXN], pvem[MAXN];
set<pair<ll, int> > fila;

void recupera(int v){
	if(jav[v]) return;
	jav[v]=1;
	rep(i,0,sz(pai[v])){
		int u = pai[v][i];
		vai[u].pb(v);
		vem[v].pb(u);
		recupera(u);
	}
}

ll solvevai(int v){
	if(v == b) return 1;
	ll & ret = pdvai[v];
	if(ret != -1) return ret;
	ret = 0;
	rep(i,0,sz(vai[v])) ret = (ret + solvevai(vai[v][i]))%mod;
	return ret;
}

ll solvevem(int v){
	if(v == a) return 1;
	ll & ret = pdvem[v];
	if(ret != -1) return ret;
	ret = 0;
	rep(i,0,sz(vem[v])) ret = (ret + solvevem(vem[v][i]))%mod;
	return ret;
}

char podevai(int v){
	if(v == b) return 1;
	char & ret = pvai[v];
	if(ret != 2) return ret;
	ret = 0;
	rep(i,0,sz(vai[v])) ret |= podevai(vai[v][i]);
	return ret;
}

char podevem(int v){
	if(v == a) return 1;
	char & ret = pvem[v];
	if(ret != 2) return ret;
	ret = 0;
	rep(i,0,sz(vem[v])) ret |= podevem(vem[v][i]);
	return ret;
}

int32_t main(){
	clr(dis,-1);
	clr(pdvai,-1);
	clr(pdvem,-1);
	clr(pvai,2);
	clr(pvem,2);
	scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
	a--, b--;
	rep(i,0,m){
		int u, v, c;
		scanf("%lld%lld%lld", &u, &v, &c);
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
		cost[u].pb(c);
		cost[v].pb(c);
	}
	dis[a]=0;
	fila.insert(mp(dis[a],a));
	while(!fila.empty()){
		ll d = fila.begin()->x;
		int v = fila.begin()->y;
		fila.erase(fila.begin());
		if(dis[v] != d) continue;
		rep(i,0,sz(adj[v])){
			int u = adj[v][i];
			int c = cost[v][i];
			if(dis[u] == -1 || dis[u] > dis[v] + c){
				pai[u].clear();
				dis[u] = dis[v] + c;
				fila.insert(mp(dis[u],u));
			}
			if(dis[u] == dis[v] + c)
				pai[u].pb(v);
		}
	}
	recupera(b);
	ll ans = solvevai(a)*solvevai(a)%mod;
	rep(i,0,n) if(2*dis[i] == dis[b] && podevai(i) && podevem(i)){
		ll q = solvevai(i)*solvevem(i)%mod;
		ans = ((ans - q*q)%mod + mod)%mod;
	}
	rep(i,0,n) rep(j,0,sz(vai[i])) if(2*dis[i] < dis[b] && 2*dis[vai[i][j]] > dis[b] && podevai(vai[i][j]) && podevem(i)){
		ll q = solvevai(vai[i][j])*solvevem(i)%mod;
		ans = ((ans - q*q)%mod + mod)%mod;
	}
	printf("%lld\n", ans);
}
