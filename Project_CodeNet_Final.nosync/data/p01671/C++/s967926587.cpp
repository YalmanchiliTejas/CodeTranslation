#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
 
using namespace std;
 
#define MAX_N (100000)

#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));

#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);
 
typedef long long lint;
 
struct Edge {
	int from, to, id;
	lint cost;
	bool inMST;
	Edge(int from, int to, lint cost, int id) : from(from), to(to), cost(cost), id(id){inMST = false;}
	Edge(){}
};
 
vector<Edge> G[MAX_N], v;
 
bool operator < (const Edge &a, const Edge &b)
{
	return (a.cost < b.cost);
}
 
bool operator > (const Edge &a, const Edge &b)
{
	return (b < a);
}
 
int par[MAX_N];
 
void init()
{
	for (int i = 0; i < MAX_N; i++)
		par[i] = i;
}
 
int find(int x)
{
	if (x == par[x]) return (x);
	return (par[x] = find(par[x]));
}
 
void unite(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	int x = u ^ v;
	x ^= ((rand() & 1) ? u : v);
	par[x] = x ^ u ^ v;
}
 
bool same(int u, int v)
{
	return (find(u) == find(v));
}
 
lint ans[MAX_N * 2];
int ord[MAX_N], dst[MAX_N], low[MAX_N];
bool vis[MAX_N];
 
void predfs(int u, int p, int &k)
{
	ord[u] = low[u] = k++;
	vis[u] = true;
	
	for (int i = 0; i < G[u].size(); i++){
		if (!vis[G[u][i].to] && v[G[u][i].id].inMST){
			predfs(G[u][i].to, u, k);
			low[u] = min(low[u], low[G[u][i].to]);
		}
		else if (G[u][i].to != p) low[u] = min(low[u], ord[G[u][i].to]);
	}
	
	dst[u] = k++;
}
 
typedef priority_queue<Edge, vector<Edge>, greater<Edge> > PQ;
 
PQ pool[MAX_N];
int id[MAX_N];
lint pCost[MAX_N], cost;
PQ *pp[MAX_N], *qq;
 
void dfs(int u, int p)
{
	pp[u] = &pool[u];
	
	for (int i = 0; i < G[u].size(); i++){
		if (G[u][i].to != p && v[G[u][i].id].inMST){
			pCost[G[u][i].to] = G[u][i].cost; id[G[u][i].to] = G[u][i].id;
			dfs(G[u][i].to, u);
			qq = pp[G[u][i].to];
			if (pp[u]->size() < qq->size()) swap(pp[u], qq);
			while (qq->size()){
				pp[u]->push(qq->top()); qq->pop();
			}
		}
		else if (G[u][i].to != p && !(ord[u] <= ord[G[u][i].to] && dst[G[u][i].to] <= dst[u])){
			pp[u]->push(G[u][i]);
		}
	}
	
	while (pp[u]->size() && ord[u] <= ord[pp[u]->top().to] && dst[pp[u]->top().to] <= dst[u])
		pp[u]->pop();
	
	if (!pp[u]->size()){
		if (~p) ans[id[u]] = -1;
	}
	else {
		if (~p) ans[id[u]] = cost - pCost[u] + pp[u]->top().cost;
	}
	
}
 
int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		G[--a].push_back(Edge(-1, --b, w, i));
		G[b].push_back(Edge(-1, a, w, i));
		v.push_back(Edge(a, b, w, i));
	}
	
	sort(v.begin(), v.end());
	
	init();
	
	int eNum = 0;
	for (int i = 0; i < v.size(); i++){
		if (!same(v[i].from, v[i].to)){
			unite(v[i].from, v[i].to);
			cost += v[i].cost;
			eNum++;
			v[v[i].id].inMST= true;
		}
	}
	
	if (eNum != n - 1) for (int i = 0; i < m; i++) printf("-1\n");
	else {
		for (int i = 0; i < m; i++){
			if (!v[i].inMST) ans[i] = cost;
		}
		int k = 0;
		
		BEGIN_STACK_EXTEND(128 * 1024 * 1024);
		predfs(0, -1, k);
		dfs(0, -1);
		END_STACK_EXTEND(128 * 1024 * 1024);

		for (int i = 0; i < m; i++){
			printf("%lld\n", ans[i]);
		}
	}
	
	return (0);
}