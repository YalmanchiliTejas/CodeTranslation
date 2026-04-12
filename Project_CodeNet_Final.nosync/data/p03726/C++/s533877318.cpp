#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const int oo = 0x3f3f3f3f;

int n, m;
vector<int> g[N];
int mark[N], deg[N];
bool del[N];

void first() {
	printf( "First\n" );
	exit(0);
}
void second() {
	printf( "Second\n" );
	exit(0);
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		deg[u]++;
		deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> z, zz;
	for( int u = 1; u <= n; u++ ) {
		if( deg[u] == 1 ) {
			z.push_back(u);
		}
	}

	int remain = n;
	while(remain) {
		for( int t = 0; t < (int)z.size(); t++ ) {
			int u = z[t];
			for( int tt = 0; tt < (int)g[u].size(); tt++ ) {
				int v = g[u][tt];
				if( del[v] ) continue;
				if( mark[v] ) first();
		//		printf( "%d mark %d\n", u, v );
				mark[v] = true;
				zz.push_back(v);
			}
		}
		/*
		printf( "z: " );
		for( int t = 0; t < (int)z.size(); t++ ) printf( "%d ", z[t] );
		printf( "\nzz: " );
		for( int t = 0; t < (int)zz.size(); t++ ) printf( "%d ", zz[t] );
		printf( "\n" );
		*/

		vector<int> zzz;
		for( int t = 0; t < z.size(); t++ ) {
			int u = z[t];
			if( !del[u] ) remain--;
			del[u] = true;
		}
		for( int t = 0; t < zz.size(); t++ ) {
			int u = zz[t];
			if( !del[u] ) remain--;
			del[u] = true;
		}
		for( int t = 0; t < zz.size(); t++ ) {
			int u = zz[t];
			for( int tt = 0; tt < (int)g[u].size(); tt++ ) {
				int v = g[u][tt];
				if( del[v] ) continue;
				--deg[v];
				if( deg[v] == 0 ) first();
				if( deg[v] == 1 ) {
					zzz.push_back(v);
				}
			}
		}
		z = zzz;
		zz.clear();
	}
	if( remain == 1 )
		first();
	else
		second();
}

