#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Tnode
{
	long long On , Off , Keep;
};

struct Task
{
	int x , y;
};

const int dx[4] = { 0 , 0 , -1 , 1 };
const int dy[4] = { -1 , 1 , 0 , 0 };
const int maxn = 107 , maxq = 10007;
	  int n , m , q;
	  long long res , Time;
	  long long T[maxn][maxn];
	  Task ask[maxq];
	  Tnode node[maxn][maxn];
	  char Map[maxn][maxn];
	  bool use[maxn][maxn];
	  
void init()
{
	for ( int i = 1 ; i <= n ; i++ ) scanf( "%s" , Map[i]+1 );
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = 1 ; j <= m ; j++ ) cin >> node[i][j].Keep;
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = 1 ; j <= m ; j++ ) cin >> node[i][j].On;
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = 1 ; j <= m ; j++ ) cin >> node[i][j].Off;
	for ( int i = 1 ; i <= q ; i++ ) scanf( "%d %d" , &ask[i].x , &ask[i].y ) , ask[i].x++ , ask[i].y++;
}

bool check_map( int x , int y )
{
	if ( x < 1 || x > n ) return false;
	if ( y < 1 || y > m ) return false;
	if ( Map[x][y] == '#' ) return false;
	return use[x][y];
}

void put_time( int x , int y , long long TIME )
{
	if ( T[x][y] == 0 ) res += node[x][y].On;
	else				res += min(node[x][y].On+node[x][y].Off,node[x][y].Keep*(TIME-T[x][y]));
	T[x][y] = TIME;
}

bool dfs( int x , int y , Task End , long long TIME )
{
	use[x][y] = false;
	if ( End.x == x && End.y == y )
	{
		Time = TIME;
		return true; 
	}
	for ( int i = 0 ; i < 4 ; i++ )
	{
		int xx = x+dx[i] , yy = y+dy[i];
		if ( check_map(xx,yy) )
			if ( dfs(xx,yy,End,TIME+1) )
			{
				put_time(x,y,TIME);
				return true;
			}	
	}
	return false;
}

void work()
{
	init();
	memset( T , 0 , sizeof(T) ); 
	Time = 1 , res = 0;
	for ( int i = 1 ; i < q ; i++ ) 
	{
		memset( use , true , sizeof(use) );
		dfs(ask[i].x,ask[i].y,ask[i+1],Time);
	}
	put_time(ask[q].x,ask[q].y,Time);
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = 1 ; j <= m ; j++ )
			if ( T[i][j] > 0 ) res += node[i][j].Off;
	cout << res << endl;
}

int main()
{
	while ( scanf( "%d %d %d" , &n , &m , &q ) != EOF ) work();
}