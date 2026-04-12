#include <algorithm>
#include <iostream>
#include <vector>
#define fi first
#define se second
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,m;
LL lazy[4*maxn];
LL tree[4*maxn];
vector<pi> v[maxn];

void push( int x , int y , int id ) {
	tree[id] += lazy[id];
	if( x != y ) {
		lazy[id*2] += lazy[id];
		lazy[id*2+1] += lazy[id];
	}
	lazy[id] = 0;
}

LL update( int cx , int cy , int qx , int qy , int id , LL val ) {
	push( cx , cy , id );
	if( qy < cx || cy < qx )
		return tree[id];
	if( qx <= cx && cy <= qy ) {
		lazy[id] += val;
		push( cx , cy , id );
		return tree[id];
	}
	int mid = (cx + cy) >> 1;
	LL left = update( cx , mid , qx , qy , id*2 , val );
	LL right = update( mid+1 , cy , qx , qy , id*2+1 , val );
	return tree[id] = max( left , right );
}

LL query( int cx , int cy , int qx , int qy , int id ) {
	push( cx , cy , id );
	if( qy < cx || cy < qx )
		return 0;
	if( qx <= cx && cy <= qy )
		return tree[id];
	int mid = (cx + cy) >> 1;
	LL left = query( cx , mid , qx , qy , id*2 );
	LL right = query( mid+1 , cy , qx , qy , id*2+1 );
	return max( left , right );
}

int main() {
	cin >> n >> m;
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		cin >> x >> y >> z;
		v[y].pb( pi( x , z ) );
	}
	for( int i = 1 ; i <= n ; i++ ) {
		LL val = query( 0 , n , 0 , i-1 , 1 );
		update( 0 , n , i , i , 1 , val );
		for( int j = 0 ; j < (int) v[i].size() ; j++ )
			update( 0 , n , v[i][j].fi , i , 1 , v[i][j].se );
	}
	cout << query( 0 , n , 0 , n , 1 );
}
