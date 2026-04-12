#include<iostream>
using namespace std ;

int N;
int square[20][20] = {} ;

void search( int x , int y , int cnt ){
	if( cnt == N*N+1 ) return ;
	
	if( square[y][x]==0 ){
		square[y][x] = cnt ;
		search( (x+1)%N , (y+1)%N , cnt+1 );
	}else {
		search( (x+N-1)%N , (y+N+1)%N , cnt );
	}
	
}

int main(){
	
	while( cin >> N , N ){
		
		for( int i=0 ; i<N ; i++ )
			for( int j=0 ; j<N ; j++ )
				square[i][j] = 0;
		
		search( N/2 , N/2+1 , 1 );
		
		for( int i=0 ; i<N ; i++ ){
			for( int j=0 ; j<N ; j++ ){
				if( square[i][j] < 1000 ) cout << ' ';
				if( square[i][j] < 100  ) cout << ' ';
				if( square[i][j] < 10   ) cout << ' ';
				cout << square[i][j] ;
			}
			cout << endl ;
		}
	}
	
	return 0;
}