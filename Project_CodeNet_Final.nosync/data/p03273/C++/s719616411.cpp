#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
#define rep_d( i, n, m ) for(int i = ( n ) - 1; i >= ( m ); i--)
#define sort_asc( X ) sort(( X ).begin(), ( X ).end())
#define sort_desc( X ) sort(( X ).begin(), ( X ).end(), greater <>())

template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int* eratosthenes( int N );
bool bit_search( int pattern, int N );
template <class T> void cumulative_sum( T array, size_t N );

const ll INF = 1LL << 60;
const int k_mod = 1e9 + 7;

typedef struct {
	vector <int> to;
	int cost;
} edge;
typedef struct {
	bool a;
	bool b;
} P;
int main( void ){
	int H, W; cin >> H >> W;
	vector <vector <P> > vec( H, vector <P>( W, P{0, true} ));
	rep( i, 0, H ){
		rep( j, 0, W ){
			char c; cin >> c;
			vec[ i ][ j ].a = ( c == '.' );
		}
	}
	queue <int> que;
	rep( i, 0, H ){
		bool can = true;
		rep( j, 0, W ){
			if (!vec[ i ][ j ].a){
				can = false;
				break;
			}
		}
		if (can){
			rep( j, 0, W )
			vec[ i ][ j ].b = false;
			que.push( i );
		}
	}
	rep( i, 0, W ){
		bool can = true;
		rep( j, 0, H ){
			if (!vec[ j ][ i ].a){
				can = false;
				break;
			}
		}
		if (can)
			rep( j, 0, H )
			vec[ j ][ i ].b = false;
	}
	rep( i, 0, H ){
		if (!que.empty() && que.front() == i){
			que.pop();
			continue;
		}
		rep( j, 0, W ){
			if (vec[ i ][ j ].b)
				cout << ( vec[ i ][ j ].a ? '.' : '#' );
		}
		cout << endl;
	}
}

int* eratosthenes( int N ){
	int* prime_array = new int[ N + 1 ];
	int lim = N;
	prime_array[ 0 ] = 0;
	prime_array[ 1 ] = 0;
	rep( i, 2, N + 1 ){
		prime_array[ i ] = 1;
	}
	rep( i, 2, lim ){
		if (prime_array[ i ] == 0)
			continue;
		lim = N / i;
		for(int j = i * 2; j < N + 1; j += i){
			prime_array[ j ] = 0;
		}
	}
	return prime_array;
}
template <class T> void cumulative_sum( T array, size_t N ) {
	rep( i, 1, N + 1 ){
		array[ i ] += array[ i - 1 ];
	}
}
template <class T> bool chmax( T& a, T b ) {
	if (a < b){
		a = b; return true;
	}
	return false;
}
template <class T> bool chmin( T& a, T b ) {
	if (a > b){
		a = b; return true;
	}
	return false;
}
bool bit_search( int pattern, int N ){
	int cnt = 0;
	rep( bit, 0, N ){
		if (pattern & ( 1 << bit )){
			cnt++;
		}
	}
	return true;
}
