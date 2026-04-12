#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second

int root;
int n;
vector<int> edge[100010];
int par[100010];

void dfs(int x){
	for(int y:edge[x]) if(par[x]!=y){
		par[y]=x; dfs(y);
	}
}

bool dead[100010];
int deg[100010];

priority_queue<pp, vector<pp>, greater<pp>> pq;

int main()
{
	read(n); for(int i=1; i<n; ++i){
		int a, b; read(a, b);
		edge[a].pb(b);
		edge[b].pb(a);
		++deg[a]; ++deg[b];
	}
	if(n == 2){
		puts("Second");
		return 0;
	}
	for(int i=1; i<=n; ++i) if(edge[i].size() != 1u) root=i;
	dfs(root);
	for(int i=1; i<=n; ++i) pq.push(pp{deg[i], i});
	while(pq.size()){
		int d, i;
		tie(d, i) = pq.top(); pq.pop();
		if(deg[i] != d || dead[i]) continue;
		if(d == 0){
			puts("First");
			return 0;
		}
		assert(d == 1);
		int v = edge[i][0];
		for(int y:edge[i]) if(!dead[y]) {v=y; break;}
		auto kill = [&](int x){
			dead[x]=1;
			for(int y:edge[x]) if(!dead[y]){
				--deg[y];
				pq.push(pp{deg[y], y});
			}
		};
		kill(i); kill(v);
	}
	puts("Second");
    return 0;
}
