#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
	while( 1 ){
		int sum = 0;
		int n, s;
		deque< int > scores;
		scanf( "%d", &n );
		if( !n ){ return 0; }
		for( int i = 0; i < n; i++ ){
			scanf( "%d", &s );
			scores.push_back( s );
		}
		sort( scores.begin(), scores.end() );
		for(deque<int>::iterator it = scores.begin() + 1; it + 1 != scores.end(); it++){
			sum += *it;
		}
		
		printf( "%d\n", sum / ( n - 2 ) );
	}
}