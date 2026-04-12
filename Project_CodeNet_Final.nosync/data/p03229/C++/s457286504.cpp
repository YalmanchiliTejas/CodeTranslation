
#include "bits/stdc++.h"
using namespace std;
multiset<int> S; 
multiset<int>::iterator it;

int main(){
	int N , Num , i;
	int left , right;
	scanf( "%d" , &N );

	for( i = 1 ; i <= N ; ++i ){
		scanf( "%d" , &Num );
		S.insert( Num );
	}

	if( N == 1 ){
		puts( "0" );
		return 0;
	}

	left = *S.begin();
	it = S.end();
	--it;
	right = *it;
	S.erase( S.begin() );
	S.erase( it );
	long long Ans = right - left;
	int f , b;

	while( int(S.size()) > 1 ){
		f = *S.begin();
		it = S.end();
		--it;
		b = *it;

		if( abs( left - f ) > abs( left - b ) ){
			if( abs( right - f ) > abs( right - b ) ){
				S.erase( S.begin() );

				if( abs( left - f ) > abs( right - f ) ){
					Ans = Ans + abs( left - f );
					left = f;
				}
				else{
					Ans = Ans + abs( right - f );
					right = f;
				}
			}
			else{
				if( abs( left - f ) > abs( right - b ) ){
					S.erase( S.begin() );
					Ans = Ans + abs( left - f );
					left = f;
				}
				else{
					S.erase( it );
					Ans = Ans + abs( right - b );
					right = b;
				}
			}
		}
		else{
			if( abs( right - f ) > abs( right - b ) ){
				if( abs( left - b ) > abs( right - f ) ){
					S.erase( it );
					Ans = Ans + abs( left - b );
					left = b;
				}
				else{
					S.erase( S.begin() );
					Ans = Ans + abs( right - f );
					right = f;
				}
			}
			else{
				S.erase( it );

				if( abs( left - b ) > abs( right - b ) ){
					Ans = Ans + abs( left - b );
					left = b;
				}
				else{
					Ans = Ans + abs( right - b );
					right = b;
				}
			}
		}
	}

	if( !S.empty() ){
		if( abs( *S.begin() - left ) > abs( *S.begin() - right ) ) 
			Ans = Ans + (abs( *S.begin() - left ));
		else Ans = Ans + abs( *S.begin() - right );
	}

	printf( "%lld\n" , Ans );
	return 0;
}