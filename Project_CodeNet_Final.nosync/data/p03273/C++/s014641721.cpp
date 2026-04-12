#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
bool graph[110][110];
bool unshowed[110][110];
int main(){
	scanf("%d%d", &n, &m);
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j ){
			char c;
			scanf("%c", &c);
			while( c != '#' && c != '.' )
				scanf("%c", &c);
			if( c == '#' )
				graph[i][j] = true;
		}
	for( int i = 1; i <= n; ++i ){
		bool con = true;
		for( int j = 1; j <= m; ++j )
			if( graph[i][j] )
				con = false;
		if( con )
			for( int j = 1; j <= m; ++j )
				unshowed[i][j] = true;
	}
	for( int j = 1; j <= m; ++j ){
		bool con = true;
		for( int i = 1; i <= n; ++i )
			if( graph[i][j] )
				con = false;
		if( con )
			for( int i = 1; i <= n; ++i )
				unshowed[i][j] = true;
	}
	for( int i = 1; i <= n; ++i ){
		bool con = true;
		for( int j = 1; j <= m; ++j ){
			if( unshowed[i][j] )
				continue;
			con = false;
			if( graph[i][j] )
				putchar('#');
			else
				putchar('.');
		}
		if( !con )
			puts("");
	}
	return 0;
}