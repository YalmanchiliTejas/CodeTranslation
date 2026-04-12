#include<bits/stdc++.h>
using namespace std ;

main(){
	int N,A,B,C,X ;
	
	while( cin>>N>>A>>B>>C>>X , N ){
		int Y[N] ;
		for( int i=0 ; i<N ; i++ ) cin >> Y[i] ;
		
		int cnt=0 ;
		for( int i=0 ; i<=10001 ; i++ ){
			if( i == 10001 ){
				cout << -1 << endl ;
				break ;
			}
			if( Y[cnt] == X ){
				if( cnt+1 == N ){
					cout << i << endl ;
					break ;
				}
				else cnt++ ;
			}
			
			X = (A*X+B)%C ;
		}
	}
}