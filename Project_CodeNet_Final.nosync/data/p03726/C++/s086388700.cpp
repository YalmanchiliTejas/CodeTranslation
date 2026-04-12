#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pb2 pop_back
#define pf push_front
#define pf2 pop_front
#define line printf("\n")
#define rep(k,i,j) for(int k = (int)i;k<(int) j;k++)
#define repd(k,i,j) for(int k = i;k>=(int)j;k--)
#define ll long long
#define pq priority_queue

int dirx[8] = {0,1,0,-1,1,1,-1,-1};
int diry[8] = {1,0,-1,0,1,-1,1,-1};

const int INF = 1e9+7;
const ll INFLL = 1e16;
const double EPS = 1e-6;

using namespace std;

const int maxn = 1e5+5;
int n, lv[maxn], id[maxn], par[maxn], vis[maxn];
vector<int> adj[maxn];

void dfs(int now, int pr, int l) {
	lv[now] = l; par[now] = pr;
	for (auto nx : adj[now]) {
		if (nx==pr) continue;
		dfs(nx,now,l+1);
	}
	return;	
}

bool cmp(int a, int b) { return lv[a]>lv[b]; }

int main(){
	scanf("%d",&n);
	
	rep(k,1,n){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	int ada = 0,chain = 1;
	
	dfs(1,-1,0);
	rep(i,1,n+1) id[i] = i;
	sort(id+1, id+1+n, cmp);
	memset(vis, 0, sizeof(vis));
	for (int i=1; i<=n; i++) {
		int no = id[i];
		if (vis[no]) continue;
	//	printf ("i = %d, par = %d\n", i, par[i]);
		if (par[no]<0 || vis[par[no]]) {
			ada = 1; break;
		}
		vis[no] = vis[par[no]] = 1;
	}
	
	if(ada)puts("First");
	else puts("Second");
	
	return 0;
}