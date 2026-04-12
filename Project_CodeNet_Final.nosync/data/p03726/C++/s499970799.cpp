#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using std::vector;
using std::priority_queue;
const int N = 100010;
int _w;

int n, deg[N], rt, pa[N], dep[N], vis[N];

struct Cmp {
	bool operator()( int a, int b ) const {
		return dep[b] > dep[a];
	}
};

priority_queue<int, vector<int>, Cmp> leaf;

namespace G {
	int head[N], nxt[N*2], to[N*2], eid;
	void init() {
		eid = 0;
		memset(head, -1, sizeof head);
	}
	void link( int u, int v ) {
		to[eid] = v, nxt[eid] = head[u], head[u] = eid++;
		to[eid] = u, nxt[eid] = head[v], head[v] = eid++;
	}
}

void dfs( int u, int fa, int d ) {
	using namespace G;
	pa[u] = fa, dep[u] = d;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( v == fa ) continue;
		dfs(v, u, d+1);
	}
}

bool check( int u ) {
	using namespace G;
	vis[u] = 1;
	int cnt = 0;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( vis[v] ) continue;
		--deg[v];
		if( deg[v] == 0 ) ++cnt;
		else if( deg[v] == 1 ) leaf.push(v);
	}
	return cnt >= 2;
}

int main() {
	_w = scanf( "%d", &n );
	G::init();
	for( int i = 0; i < n-1; ++i ) {
		int u, v;
		_w = scanf( "%d%d", &u, &v );
		G::link(u, v);
		++deg[u], ++deg[v];
	}
	if( n == 2 ) return puts("Second"), 0;
	for( int i = 1; i <= n; ++i )
		if( deg[i] != 1 ) {
			rt = i;
			break;
		}
	dfs(rt, 0, 1);
	for( int i = 1; i <= n; ++i )
		if( deg[i] == 1 )
			leaf.push(i);
	while( !leaf.empty() ) {
		int u = leaf.top();
		leaf.pop();
		if( check( pa[u] ) ) return puts("First"), 0;
	}
	return puts("Second"), 0;
}

