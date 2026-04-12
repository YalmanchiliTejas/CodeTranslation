#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<deque>

using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for(int i=a;i<b;++i)
#define per(i, a, b) for(int i=b-1;i>=a;--i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

////////////////

string const F = "First";
string const S = "Second";

int const N = 1e5 + 41;

vector<int> e[N];
int root;
int l[N];
int n;
int cnt[N];
int par[N];
int w[N];

deque<int> q;

void print(string ans){
	cout << ans << endl;
	exit(0);
}

int dfs(int u, int p){
	if(sz(e[u]) == 1) l[u] = 1;
	par[u] = p;
	int cnt = 0;
	rep(i, 0, sz(e[u])){
		int to = e[u][i];
		if(to == p) continue;
		cnt += dfs(to, u);
	}
	if(cnt > 1) print(F);
	return l[u];
}

void solve(){
	cin >> n;
	rep(i, 0, n-1){
		int a, b;
		cin >> a >> b;
		--a;--b;
		e[a].pb(b);
		e[b].pb(a);
	}

	rep(i, 0, n) if(sz(e[i]) > sz(e[root])) root = i;
	++cnt[root];
	dfs(root, -1);
	rep(i, 0, n){
		cnt[i] = sz(e[i]);
		if(l[i]) q.pb(i);
	}
	while(sz(q)){
		int v = q.front();
		q.pop_front();
		if(par[v] == -1){
			continue;
		}
		if(!w[v] && w[par[v]]) print(F);
		--cnt[par[v]];
		if(cnt[par[v]] == 1) q.pb(par[v]);
		if(!w[v]){
			w[par[v]] = 1;
			w[v] = 1;
		}
	}
	rep(i, 0, n) if(!w[i]) print(F);

	print(S);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}