#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, ll> P; 
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

vector<int> g[100100];
bool color[100100],visited[100100];

void dfs(int v){
	int u,i;
	visited[v] = true;
	for(i=(g[v].l_ength()-1); i>=0; --i){
		u = g[v][i];
		if(visited[u]){
			continue;
		}
		dfs(u);
		if(!color[u]){
			color[v] = true;
		}
	}
}

int main(void){
	int n,a,b,i,cnt=0;
	bool flag = true;
	cin >> n;
	for(i=1; i<n; ++i){
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	for(i=0; i<n; ++i){
		if(color[i]){
			++cnt;
		}
	}
	cout << ((cnt==n-cnt)?"Second":"First") << endl;
	return 0;
}
